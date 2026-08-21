# Myst offsets / GitHub load diagnostics — checks if remote offsets can reach GitHub and match Roblox.
# Friend: run in Admin PowerShell, copy ALL console output and send it.
#Requires -Version 5.1

$ErrorActionPreference = 'Continue'

$script:BaseUrl = 'https://raw.githubusercontent.com/2kr5x/Myst/main'
$script:FailCount = 0
$script:WarnCount = 0
$script:ExpectedRobloxVersion = $null
$script:ExpectedOffsetCount = 0

function Get-OffsetsLogPath {
    $dir = Join-Path $env:USERPROFILE 'Desktop'
    if (-not (Test-Path -LiteralPath $dir)) { $dir = $env:TEMP }
    return Join-Path $dir ("myst-offsets-debug-{0}.txt" -f (Get-Date -Format 'yyyyMMdd-HHmmss'))
}

$script:LogPath = Get-OffsetsLogPath

function Write-OffDiag {
    param(
        [Parameter(Mandatory = $true)][string]$Message,
        [ValidateSet('INFO', 'PASS', 'WARN', 'FAIL')]
        [string]$Level = 'INFO'
    )
    $line = "[{0}] [{1}] {2}" -f (Get-Date -Format 'HH:mm:ss.fff'), $Level, $Message
    $color = switch ($Level) {
        'PASS' { 'Green' }
        'FAIL' { 'Red' }
        'WARN' { 'Yellow' }
        default { 'White' }
    }
    Write-Host $line -ForegroundColor $color
    try { Add-Content -LiteralPath $script:LogPath -Value $line -Encoding UTF8 } catch {}
    if ($Level -eq 'FAIL') { $script:FailCount++ }
    if ($Level -eq 'WARN') { $script:WarnCount++ }
}

function Enable-Tls {
    try {
        [Net.ServicePointManager]::SecurityProtocol =
            [Net.SecurityProtocolType]::Tls12 -bor [Net.SecurityProtocolType]::Tls13
    } catch {
        [Net.ServicePointManager]::SecurityProtocol = [Net.SecurityProtocolType]::Tls12
    }
}

function Test-Admin {
    $identity = [Security.Principal.WindowsIdentity]::GetCurrent()
    $principal = New-Object Security.Principal.WindowsPrincipal($identity)
    return $principal.IsInRole([Security.Principal.WindowsBuiltInRole]::Administrator)
}

function Get-RunningRobloxVersion {
    $proc = Get-Process -Name 'RobloxPlayerBeta' -ErrorAction SilentlyContinue | Select-Object -First 1
    if (-not $proc) { return $null }

    try {
        $path = (Get-CimInstance Win32_Process -Filter "ProcessId=$($proc.Id)" -ErrorAction Stop).ExecutablePath
        if ($path -match '\\Versions\\(version-[^\\]+)\\') {
            return [PSCustomObject]@{
                Version = $Matches[1]
                Path    = $path
                Pid     = $proc.Id
            }
        }
    } catch {}

    return [PSCustomObject]@{
        Version = $null
        Path    = $null
        Pid     = $proc.Id
    }
}

function Test-DnsHost {
    param([string]$HostName)
    try {
        $result = [System.Net.Dns]::GetHostAddresses($HostName)
        $ips = @($result | ForEach-Object { $_.IPAddressToString }) -join ', '
        Write-OffDiag "DNS $HostName -> $ips" 'PASS'
        return $true
    } catch {
        Write-OffDiag "DNS $HostName FAILED: $($_.Exception.Message)" 'FAIL'
        return $false
    }
}

function Test-OffsetUrl {
    param(
        [string]$Url,
        [string]$Label,
        [int]$MinBytes = 512
    )
    try {
        Enable-Tls
        $resp = Invoke-WebRequest -Uri $Url -UseBasicParsing -TimeoutSec 30 -Headers @{
            'Cache-Control' = 'no-cache, no-store, must-revalidate'
            'Pragma'        = 'no-cache'
        }
        $size = if ($resp.RawContentLength -ge 0) { $resp.RawContentLength } else { $resp.Content.Length }
        if ($size -lt $MinBytes) {
            Write-OffDiag "$Label too small ($size bytes, need >= $MinBytes): $Url" 'FAIL'
            return $null
        }
        Write-OffDiag "$Label downloaded OK ($size bytes)" 'PASS'
        return $resp
    } catch {
        Write-OffDiag "$Label DOWNLOAD FAILED: $Url :: $($_.Exception.Message)" 'FAIL'
        return $null
    }
}

function Test-OffsetsHppContent {
    param([string]$Body, [string]$SourceLabel)

    if ([string]::IsNullOrWhiteSpace($Body)) {
        Write-OffDiag "$SourceLabel hpp body empty" 'FAIL'
        return $false
    }

    $checks = @(
        @{ Need = 'namespace offsets'; Label = 'namespace offsets' }
        @{ Need = 'roblox_version'; Label = 'roblox_version field' }
        @{ Need = 'ModelInstance'; Label = 'ModelInstance offset' }
        @{ Need = 'namespace VisualEngine'; Label = 'VisualEngine namespace' }
        @{ Need = 'Health = '; Label = 'Humanoid Health offset' }
    )

    $ok = $true
    foreach ($c in $checks) {
        if ($Body -notmatch [regex]::Escape($c.Need)) {
            Write-OffDiag "$SourceLabel missing $($c.Label)" 'FAIL'
            $ok = $false
        }
    }
    if (-not $ok) { return $false }

    if ($Body -match 'roblox_version\[64\]\s*=\s*"([^"]+)"') {
        $ver = $Matches[1]
        Write-OffDiag "$SourceLabel roblox_version in hpp: $ver" 'INFO'
        if ($script:ExpectedRobloxVersion -and $ver -ne $script:ExpectedRobloxVersion) {
            Write-OffDiag "$SourceLabel version mismatch vs update.json ($script:ExpectedRobloxVersion)" 'WARN'
        } else {
            Write-OffDiag "$SourceLabel version matches update.json" 'PASS'
        }
    } else {
        Write-OffDiag "$SourceLabel could not parse roblox_version string" 'WARN'
    }

    $offsetLines = @([regex]::Matches($Body, 'inline\s+uintptr_t\s+\w+\s*=')).Count
    Write-OffDiag "$SourceLabel parsed ~$offsetLines offset entries" 'INFO'
    if ($offsetLines -lt 50) {
        Write-OffDiag "$SourceLabel looks truncated (expected 200+ offset lines)" 'FAIL'
        return $false
    }

    Write-OffDiag "$SourceLabel hpp structure OK" 'PASS'
    return $true
}

function Test-OffsetsJsonContent {
    param([string]$Body, [string]$SourceLabel)

    if ([string]::IsNullOrWhiteSpace($Body)) {
        Write-OffDiag "$SourceLabel json body empty" 'FAIL'
        return $false
    }

    try {
        $json = $Body | ConvertFrom-Json
    } catch {
        Write-OffDiag "$SourceLabel JSON parse FAILED: $($_.Exception.Message)" 'FAIL'
        return $false
    }

    $metaVersion = $null
    $total = 0
    if ($json.metadata) {
        $metaVersion = [string]$json.metadata.roblox_version
        if ($json.metadata.total_offsets) { $total = [int]$json.metadata.total_offsets }
    }

    if (-not $metaVersion) {
        Write-OffDiag "$SourceLabel missing metadata.roblox_version" 'FAIL'
        return $false
    }

    Write-OffDiag "$SourceLabel metadata.roblox_version: $metaVersion" 'INFO'
    if ($script:ExpectedRobloxVersion -and $metaVersion -ne $script:ExpectedRobloxVersion) {
        Write-OffDiag "$SourceLabel version mismatch vs update.json" 'WARN'
    } else {
        Write-OffDiag "$SourceLabel version matches update.json" 'PASS'
    }

    $offsetKeys = @($json.offsets.PSObject.Properties.Name)
    Write-OffDiag "$SourceLabel offset namespaces: $($offsetKeys.Count)" 'INFO'
    if ($offsetKeys.Count -lt 10) {
        Write-OffDiag "$SourceLabel offsets object too small" 'FAIL'
        return $false
    }

    if ($total -gt 0 -and $script:ExpectedOffsetCount -gt 0 -and $total -ne $script:ExpectedOffsetCount) {
        Write-OffDiag "$SourceLabel total_offsets=$total expected=$($script:ExpectedOffsetCount)" 'WARN'
    }

    Write-OffDiag "$SourceLabel JSON structure OK" 'PASS'
    return $true
}

function Test-GitHubApiReachable {
    try {
        Enable-Tls
        $r = Invoke-WebRequest -Uri 'https://api.github.com/repos/2kr5x/Myst' -UseBasicParsing -TimeoutSec 20 -Headers @{
            'User-Agent' = 'Myst-Offsets-Diagnose'
        }
        Write-OffDiag "GitHub API repo reachable ($($r.StatusCode))" 'PASS'
        return $true
    } catch {
        Write-OffDiag "GitHub API blocked or unreachable: $($_.Exception.Message)" 'WARN'
        return $false
    }
}

# --- Main ---
Set-Content -LiteralPath $script:LogPath -Value @(
    '=== Myst offsets / GitHub diagnose ==='
    "Started: $(Get-Date -Format 'yyyy-MM-dd HH:mm:ss')"
    "Computer: $env:COMPUTERNAME"
    "User: $env:USERNAME"
    '======================================'
) -Encoding UTF8 -Force

Write-OffDiag '=== MYST OFFSETS / GITHUB DIAGNOSE ===' 'INFO'
Write-OffDiag ("Log file: {0}" -f $script:LogPath) 'INFO'

if (Test-Admin) { Write-OffDiag 'Administrator: YES' 'PASS' }
else { Write-OffDiag 'Administrator: NO (install may still work; offsets test does not require admin)' 'WARN' }

Write-OffDiag ("OS: {0}" -f (Get-CimInstance Win32_OperatingSystem).Caption) 'INFO'
Write-OffDiag ("PowerShell: {0}" -f $PSVersionTable.PSVersion) 'INFO'

Write-OffDiag '--- DNS ---' 'INFO'
Test-DnsHost 'raw.githubusercontent.com' | Out-Null
Test-DnsHost 'github.com' | Out-Null
Test-GitHubApiReachable | Out-Null

Write-OffDiag '--- update.json (manifest) ---' 'INFO'
$manifestResp = Test-OffsetUrl -Url "$script:BaseUrl/update.json" -Label 'update.json' -MinBytes 64
$manifest = $null
if ($manifestResp) {
    try {
        $raw = [string]$manifestResp.Content
        if ($raw.Length -gt 0 -and ([int][char]$raw[0] -eq 0xFEFF)) { $raw = $raw.Substring(1) }
        $manifest = $raw | ConvertFrom-Json
        $script:ExpectedRobloxVersion = [string]$manifest.roblox_version
        $script:ExpectedOffsetCount = [int]$manifest.offsets_count
        Write-OffDiag ("Myst version: {0}" -f $manifest.version) 'INFO'
        Write-OffDiag ("Embedded/remote Roblox version: {0}" -f $script:ExpectedRobloxVersion) 'INFO'
        Write-OffDiag ("Offsets count: {0}" -f $script:ExpectedOffsetCount) 'INFO'
        Write-OffDiag ("offsets_url: {0}" -f $manifest.offsets_url) 'INFO'
        Write-OffDiag ("offsets_json_url: {0}" -f $manifest.offsets_json_url) 'INFO'
    } catch {
        Write-OffDiag "update.json parse FAILED: $($_.Exception.Message)" 'FAIL'
    }
}

Write-OffDiag '--- Roblox client version (must match offsets) ---' 'INFO'
$rbx = Get-RunningRobloxVersion
if ($rbx -and $rbx.Version) {
    Write-OffDiag ("Roblox RUNNING PID {0}" -f $rbx.Pid) 'PASS'
    Write-OffDiag ("Roblox path: {0}" -f $rbx.Path) 'INFO'
    Write-OffDiag ("Running Roblox version: {0}" -f $rbx.Version) 'INFO'
    if ($script:ExpectedRobloxVersion) {
        if ($rbx.Version -eq $script:ExpectedRobloxVersion) {
            Write-OffDiag 'Roblox version MATCHES Myst offsets — embedded offsets should work offline' 'PASS'
        } else {
            Write-OffDiag ("Roblox version MISMATCH: running={0} myst={1}" -f $rbx.Version, $script:ExpectedRobloxVersion) 'FAIL'
            Write-OffDiag 'MISMATCH FIX: Roblox updated OR friend is on old Myst — need Auto offsets + GitHub OR new Myst build' 'INFO'
        }
    }
} else {
    Write-OffDiag 'Roblox NOT running — open Roblox, join a game, re-run this script for version check' 'WARN'
}

Write-OffDiag '--- GitHub offset URLs (same paths Myst uses) ---' 'INFO'
$hppUrls = @(
    "$script:BaseUrl/offsets.hpp"
    'https://raw.githubusercontent.com/2kr5x/Myst/refs/heads/main/offsets.hpp'
    'https://raw.githubusercontent.com/2kr5x/Myst/main/offsets.hpp'
)
if ($manifest -and $manifest.offsets_url) { $hppUrls = @([string]$manifest.offsets_url) + $hppUrls | Select-Object -Unique }

$jsonUrls = @(
    "$script:BaseUrl/offsets.json"
    'https://raw.githubusercontent.com/2kr5x/Myst/refs/heads/main/offsets.json'
    'https://raw.githubusercontent.com/2kr5x/Myst/main/offsets.json'
)
if ($manifest -and $manifest.offsets_json_url) { $jsonUrls = @([string]$manifest.offsets_json_url) + $jsonUrls | Select-Object -Unique }

$hppOk = $false
foreach ($url in $hppUrls) {
    Write-OffDiag "Trying hpp: $url" 'INFO'
    $resp = Test-OffsetUrl -Url $url -Label 'offsets.hpp' -MinBytes 4096
    if ($resp -and (Test-OffsetsHppContent -Body $resp.Content -SourceLabel $url)) {
        $hppOk = $true
        break
    }
}
if (-not $hppOk) {
    Write-OffDiag 'ALL offsets.hpp URL content checks failed (download may still work — see PASS download lines)' 'WARN'
}

$jsonOk = $false
foreach ($url in $jsonUrls) {
    Write-OffDiag "Trying json: $url" 'INFO'
    $resp = Test-OffsetUrl -Url $url -Label 'offsets.json' -MinBytes 1024
    if ($resp -and (Test-OffsetsJsonContent -Body $resp.Content -SourceLabel $url)) {
        $jsonOk = $true
        break
    }
}
if (-not $jsonOk) {
    Write-OffDiag 'ALL offsets.json URLs failed — JSON fallback blocked' 'FAIL'
} elseif ($rbx -and $rbx.Version -and $script:ExpectedRobloxVersion -and $rbx.Version -ne $script:ExpectedRobloxVersion) {
    Write-OffDiag ("CRITICAL: Roblox {0} != Myst offsets {1} — ESP/features CANNOT work until Myst is rebuilt with new offsets" -f $rbx.Version, $script:ExpectedRobloxVersion) 'FAIL'
}

Write-OffDiag '--- What Myst settings mean for your friend ---' 'INFO'
Write-OffDiag 'Embedded (offline): uses offsets baked into DLL/EXE — NO GitHub needed if Roblox version matches' 'INFO'
Write-OffDiag 'Auto (GitHub on mismatch): tries GitHub ONLY when Roblox version differs from embedded' 'INFO'
if (-not $hppOk -and -not $jsonOk) {
    Write-OffDiag 'Friend has GitHub BLOCKED -> must use Embedded mode AND Roblox version must match Myst build' 'WARN'
}
if ($rbx -and $rbx.Version -and $script:ExpectedRobloxVersion -and $rbx.Version -ne $script:ExpectedRobloxVersion) {
    if (-not $hppOk) {
        Write-OffDiag 'WORST CASE: version mismatch + GitHub blocked = ESP/features will NOT work until new Myst build' 'FAIL'
    } else {
        Write-OffDiag 'Version mismatch but GitHub works -> set Offsets Source to Auto in Myst settings' 'INFO'
    }
}

Write-OffDiag '--- Local Myst install (for reference) ---' 'INFO'
$dll = Join-Path $env:SystemRoot 'Microsoft.NET\Framework64\sbscmp64_mscorwks.dll'
$exe = Join-Path $env:APPDATA 'AutoClicker\AutoClicker-3.0.exe'
if (Test-Path -LiteralPath $dll) {
    $i = Get-Item -LiteralPath $dll -Force
    Write-OffDiag ("Private DLL: {0} bytes, modified {1}" -f $i.Length, $i.LastWriteTime) 'INFO'
} else {
    Write-OffDiag 'Private DLL not installed' 'WARN'
}
if (Test-Path -LiteralPath $exe) {
    $i = Get-Item -LiteralPath $exe -Force
    Write-OffDiag ("Public EXE: {0} bytes, modified {1}" -f $i.Length, $i.LastWriteTime) 'INFO'
} else {
    Write-OffDiag 'Public EXE not installed' 'WARN'
}

Write-OffDiag '--- SUMMARY ---' 'INFO'
if ($script:FailCount -eq 0 -and $script:WarnCount -eq 0) {
    Write-OffDiag 'Offsets/GitHub look OK — if ESP still broken, send this log + which install (DLL or EXE)' 'PASS'
} elseif ($script:FailCount -eq 0) {
    Write-OffDiag ("{0} warning(s) — read WARN lines above" -f $script:WarnCount) 'WARN'
} else {
    Write-OffDiag ("{0} FAIL(s), {1} WARN(s) — send this entire log" -f $script:FailCount, $script:WarnCount) 'FAIL'
}

try {
    Get-Content -LiteralPath $script:LogPath -Raw | Set-Clipboard
    Write-Host ''
    Write-Host '  Copied full report to clipboard.' -ForegroundColor Green
} catch {
    Write-Host ''
    Write-Host '  Could not copy to clipboard — manually copy console output.' -ForegroundColor Yellow
}

Write-Host ("  Saved: {0}" -f $script:LogPath) -ForegroundColor Cyan
Write-Host '  Paste everything and send to support.' -ForegroundColor DarkGray
Write-Host ''

if ($script:FailCount -gt 0) { exit 1 }
exit 0
