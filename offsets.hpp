/*
 * Embedded offsets synced from https://offsets.imtheo.lol
 * Roblox Version: version-e7d81637d42c4b23
 * Do not use remote auto-fetch — embedded only at runtime.
 */

#pragma once
#include <cstdint>

// clang-format off
namespace offsets {
    inline char roblox_version[64] = "version-e7d81637d42c4b23";

    namespace BasePart {
         inline uintptr_t CastShadow = 0x135;
         inline uintptr_t Color3 = 0x1A8;
         inline uintptr_t Locked = 0x136;
         inline uintptr_t Massless = 0x137;
         inline uintptr_t Overlap = 0x1F8;
         inline uintptr_t Primitive = 0x188;
         inline uintptr_t Reflectance = 0x10C;
         inline uintptr_t Shape = 0x1B8;
         inline uintptr_t Transparency = 0x130;
    }

    namespace BloomEffect {
         inline uintptr_t Enabled = 0xB0;
         inline uintptr_t Intensity = 0xB8;
         inline uintptr_t Size = 0xBC;
         inline uintptr_t Threshold = 0xC0;
    }

    namespace BlurEffect {
         inline uintptr_t Enabled = 0xB0;
         inline uintptr_t Size = 0xB8;
    }

    namespace ByteCode {
         inline uintptr_t Pointer = 0x10;
         inline uintptr_t Size = 0x20;
    }

    namespace CallInfo {
         inline uintptr_t base = 0x10;
         inline uintptr_t func = 0x18;
         inline uintptr_t nresults = 0x28;
         inline uintptr_t top = 0x0;
    }

    namespace Callback {
         inline uintptr_t DataModelAdjustment = 0x1C8;
         inline uintptr_t Reference = 0x34;
         inline uintptr_t WeakChain = 0x38;
         inline uintptr_t WeakObject = 0x18;
         inline uintptr_t Wrapper = 0x18;
    }

    namespace Camera {
         inline uintptr_t CFrame = 0xD8;
         inline uintptr_t CameraSubject = 0xC8;
         inline uintptr_t CameraType = 0x138;
         inline uintptr_t FieldOfView = 0x140;
         inline uintptr_t Position = 0xFC;
         inline uintptr_t Rotation = 0xD8;
         inline uintptr_t Viewport = 0x28C;
         inline uintptr_t ViewportSize = 0x2CC;
    }

    namespace Capabilities {
         inline uintptr_t Capabilities = 0x28;
    }

    namespace CharacterMesh {
         inline uintptr_t BaseTextureId = 0xC8;
         inline uintptr_t BodyPart = 0x148;
         inline uintptr_t MeshId = 0xF8;
         inline uintptr_t OverlayTextureId = 0x128;
    }

    namespace ClassDescriptor {
         inline uintptr_t CallbackEntryKindValue = 0x4;
         inline uintptr_t PropertyEntryDescriptor = 0x0;
         inline uintptr_t PropertyEntryKind = 0x8;
         inline uintptr_t PropertyMap = 0x250;
         inline uintptr_t PropertyMapBucketIndices = 0x2C8;
         inline uintptr_t PropertyMapBucketMask = 0x2D8;
         inline uintptr_t PropertyMapEntries = 0x2D0;
         inline uintptr_t PropertyMapEntrySize = 0x10;
    }

    namespace Closure {
         inline uintptr_t f = 0x28;
         inline uintptr_t isC = 0x3;
         inline uintptr_t nupvalues = 0x4;
         inline uintptr_t stacksize = 0x5;
    }

    namespace ColorCorrectionEffect {
         inline uintptr_t Brightness = 0xC4;
         inline uintptr_t Contrast = 0xC8;
         inline uintptr_t Enabled = 0xB0;
         inline uintptr_t TintColor = 0xB8;
    }

    namespace DataModel {
         inline uintptr_t CreatorId = 0x180;
         inline uintptr_t GameId = 0x188;
         inline uintptr_t GameLoaded = 0x5D8;
         inline uintptr_t JobId = 0x118;
         inline uintptr_t PlaceId = 0x190;
         inline uintptr_t ServerIP = 0x5C0;
         inline uintptr_t Workspace = 0x158;
    }

    namespace DepthOfFieldEffect {
         inline uintptr_t Enabled = 0xB0;
         inline uintptr_t FarIntensity = 0xB8;
         inline uintptr_t FocusDistance = 0xBC;
         inline uintptr_t InFocusRadius = 0xC0;
         inline uintptr_t NearIntensity = 0xC4;
    }

    namespace EventDescriptor {
         inline uintptr_t Signature = 0x48;
    }

    namespace EventInstance {
         inline uintptr_t Descriptor = 0x0;
         inline uintptr_t OwningInstance = 0x18;
    }

    namespace EventSignature {
         inline uintptr_t FirstParameter = 0x8;
         inline uintptr_t MaximumParameters = 0x80;
         inline uintptr_t ParameterStride = 0x70;
    }

    namespace ExtraSpace {
         inline uintptr_t IsCoreScript = 0x168;
         inline uintptr_t RequireBypass = 0xA00;
         inline uintptr_t ScriptContextToResume = 0x8E0;
         inline uintptr_t ScriptContextToState = 0x300;
    }

    namespace FakeDataModel {
         inline uintptr_t Pointer = 0x8D22868;
         inline uintptr_t RealDataModel = 0x1F8;
    }

    namespace FastClusterEntity {
         inline uintptr_t AlphaByte = 0x14;
         inline uintptr_t BBoxMaxX = 0xA4;
         inline uintptr_t BBoxMaxY = 0xA8;
         inline uintptr_t BBoxMaxZ = 0xAC;
         inline uintptr_t BBoxMinX = 0x98;
         inline uintptr_t BBoxMinY = 0x9C;
         inline uintptr_t BBoxMinZ = 0xA0;
         inline uintptr_t ContextPtr = 0x8;
         inline uintptr_t DecalMaterialPtr = 0x48;
         inline uintptr_t MaterialPtr = 0x20;
         inline uintptr_t PrimitiveIndexArrayPtr = 0x80;
         inline uintptr_t PrimitivePoolPtr = 0x1A0;
         inline uintptr_t RenderQueueId = 0x10;
         inline uintptr_t TechniqueArrayPtr = 0x70;
         inline uintptr_t VTableRva = 0x0;
    }

    namespace Functions {
         inline uintptr_t Raycast = 0xe9f200;
    }

    namespace GarbageCollector {
         inline uintptr_t L_global = 0x28;
         inline uintptr_t g_freepages = 0x68;
         inline uintptr_t g_gcstate = 0x39;
         inline uintptr_t g_gcstepmul = 0x44;
         inline uintptr_t g_gcstepsize = 0x40;
         inline uintptr_t g_gray = 0x20;
         inline uintptr_t g_grayagain = 0x18;
         inline uintptr_t g_weak = 0x10;
    }

    namespace GuiBase2D {
         inline uintptr_t AbsolutePosition = 0x10C;
         inline uintptr_t AbsoluteRotation = 0xE8;
         inline uintptr_t AbsoluteSize = 0x114;
    }

    namespace GuiObject {
         inline uintptr_t Active = 0x5A8;
         inline uintptr_t AnchorPoint = 0x558;
         inline uintptr_t AutomaticSize = 0x560;
         inline uintptr_t BackgroundColor3 = 0x540;
         inline uintptr_t BackgroundTransparency = 0x54C;
         inline uintptr_t BorderColor3 = 0x54C;
         inline uintptr_t BorderMode = 0x568;
         inline uintptr_t BorderSizePixel = 0x56C;
         inline uintptr_t ClipsDescendants = 0x5A9;
         inline uintptr_t GuiState = 0x578;
         inline uintptr_t Interactable = 0x5AB;
         inline uintptr_t LayoutOrder = 0x57C;
         inline uintptr_t Position = 0x510;
         inline uintptr_t Rotation = 0xE8;
         inline uintptr_t Selectable = 0x5AC;
         inline uintptr_t SelectionOrder = 0x598;
         inline uintptr_t Size = 0x530;
         inline uintptr_t SizeConstraint = 0x5A0;
         inline uintptr_t Visible = 0x5AD;
         inline uintptr_t ZIndex = 0x5A4;
    }

    namespace Humanoid {
         inline uintptr_t AutoJumpEnabled = 0x1D4;
         inline uintptr_t AutoRotate = 0x1D5;
         inline uintptr_t AutomaticScalingEnabled = 0x1D6;
         inline uintptr_t BreakJointsOnDeath = 0x1D7;
         inline uintptr_t CameraOffset = 0x128;
         inline uintptr_t DisplayDistanceType = 0x180;
         inline uintptr_t EvaluateStateMachine = 0x1D8;
         inline uintptr_t Health = 0x190;
         inline uintptr_t HealthDisplayDistance = 0x188;
         inline uintptr_t HealthDisplayType = 0x18C;
         inline uintptr_t HipHeight = 0x194;
         inline uintptr_t HumanoidState = 0x8C0;
         inline uintptr_t HumanoidStateID = 0x20;
         inline uintptr_t Jump = 0x1DA;
         inline uintptr_t JumpHeight = 0x1A0;
         inline uintptr_t JumpPower = 0x1A4;
         inline uintptr_t MaxHealth = 0x1A8;
         inline uintptr_t MaxSlopeAngle = 0x1AC;
         inline uintptr_t NameDisplayDistance = 0x1B0;
         inline uintptr_t NameOcclusion = 0x1B4;
         inline uintptr_t PlatformStand = 0x1DC;
         inline uintptr_t RequiresNeck = 0x1DD;
         inline uintptr_t RigType = 0x1C0;
         inline uintptr_t SeatPart = 0x108;
         inline uintptr_t Sit = 0x1DD;
         inline uintptr_t TargetPoint = 0x14C;
         inline uintptr_t UseJumpPower = 0x1E0;
         inline uintptr_t WalkSpeed = 0x1D0;
         inline uintptr_t WalkSpeedCheck = 0x3BC;
         inline uintptr_t WalkTimer = 0x408;
         inline uintptr_t WalkToPoint = 0x164;
         inline uintptr_t Walkspeed = 0x1D0;
         inline uintptr_t WalkspeedCheck = 0x3BC;
    }

    namespace Hyperion {
         inline uintptr_t Bitmap = 0x1473148;
         inline uintptr_t InstrumentationCallback = 0x800400;
    }

    namespace InputObject {
         inline uintptr_t MousePosition = 0xD4;
    }

    namespace Instance {
         inline uintptr_t Children = 0x78;
         inline uintptr_t ChildrenEnd = 0x8;
         inline uintptr_t ChildrenStart = 0x78;
         inline uintptr_t ClassDescriptor = 0x18;
         inline uintptr_t ClassName = 0x8;
         inline uintptr_t ComponentMap = 0x38;
         inline uintptr_t Name = 0x8;
         inline uintptr_t NameContainer = 0x70;
         inline uintptr_t Parent = 0x68;
    }

    namespace Lighting {
         inline uintptr_t Ambient = 0xD0;
         inline uintptr_t Atmosphere = 0x1D8;
         inline uintptr_t Brightness = 0x118;
         inline uintptr_t ClockTime = 0xC8;
         inline uintptr_t ColorShift_Bottom = 0xE8;
         inline uintptr_t ColorShift_Top = 0xDC;
         inline uintptr_t EnvironmentDiffuseScale = 0x11C;
         inline uintptr_t EnvironmentSpecularScale = 0x120;
         inline uintptr_t ExposureCompensation = 0x124;
         inline uintptr_t FogColor = 0xF4;
         inline uintptr_t FogEnd = 0x12C;
         inline uintptr_t FogStart = 0x130;
         inline uintptr_t GlobalShadows = 0x144;
         inline uintptr_t OutdoorAmbient = 0x100;
         inline uintptr_t ShadowSoftness = 0x13C;
         inline uintptr_t Sky = 0x1C8;
    }

    namespace LightingParameters {
         inline uintptr_t GeographicLatitude = 0x134;
         inline uintptr_t LightColor = 0x15C;
         inline uintptr_t LightDirection = 0x168;
         inline uintptr_t SkyAmbient = 0x150;
         inline uintptr_t SkyAmbient2 = 0x138;
         inline uintptr_t Source = 0x174;
         inline uintptr_t TrueMoonPosition = 0x184;
         inline uintptr_t TrueSunPosition = 0x178;
    }

    namespace LocalScript {
         inline uintptr_t Bytecode = 0x190;
         inline uintptr_t Hash = 0x1A0;
    }

    namespace MaterialColors {
         inline uintptr_t Asphalt = 0x30;
         inline uintptr_t Basalt = 0x27;
         inline uintptr_t Brick = 0xF;
         inline uintptr_t Cobblestone = 0x33;
         inline uintptr_t Concrete = 0xC;
         inline uintptr_t CrackedLava = 0x2D;
         inline uintptr_t Glacier = 0x1B;
         inline uintptr_t Grass = 0x6;
         inline uintptr_t Ground = 0x2A;
         inline uintptr_t Ice = 0x36;
         inline uintptr_t LeafyGrass = 0x39;
         inline uintptr_t Limestone = 0x3F;
         inline uintptr_t Mud = 0x24;
         inline uintptr_t Pavement = 0x42;
         inline uintptr_t Rock = 0x18;
         inline uintptr_t Salt = 0x3C;
         inline uintptr_t Sand = 0x12;
         inline uintptr_t Sandstone = 0x21;
         inline uintptr_t Slate = 0x9;
         inline uintptr_t Snow = 0x1E;
         inline uintptr_t WoodPlanks = 0x15;
    }

    namespace MaterialLayer {
         inline uintptr_t ColorData = 0x24;
         inline uintptr_t FillModeByte = 0x11;
         inline uintptr_t Flags2 = 0x20;
         inline uintptr_t MatFlags = 0x18;
         inline uintptr_t Param = 0x1C;
         inline uintptr_t Stride = 0x88;
    }

    namespace MeshPart {
         inline uintptr_t MeshId = 0x310;
         inline uintptr_t TextureId = 0x340;
    }

    namespace Misc {
         inline uintptr_t AnimationId = 0xC0;
    }

    namespace ModuleScript {
         inline uintptr_t Bytecode = 0x138;
         inline uintptr_t Hash = 0x148;
    }

    namespace MouseService {
         inline uintptr_t InputObject = 0xF0;
         inline uintptr_t InputObject2 = 0x100;
         inline uintptr_t MousePosition = 0xD4;
    }

    namespace Player {
         inline uintptr_t AccountAge = 0x35C;
         inline uintptr_t Character = 0x298;
         inline uintptr_t DisplayName = 0xB8;
         inline uintptr_t HealthDisplayDistance = 0x394;
         inline uintptr_t LocalPlayer = 0x130;
         inline uintptr_t LocaleId = 0x118;
         inline uintptr_t MaxZoomDistance = 0x368;
         inline uintptr_t MinZoomDistance = 0x36C;
         inline uintptr_t ModelInstance = 0x298;
         inline uintptr_t NameDisplayDistance = 0x3A4;
         inline uintptr_t Team = 0x2D8;
         inline uintptr_t TeamColor = 0x3B0;
         inline uintptr_t UserId = 0xD0;
    }

    namespace Players {
         inline uintptr_t LocalPlayer = 0x130;
    }

    namespace Primitive {
         inline uintptr_t AssemblyAngularVelocity = 0x104;
         inline uintptr_t AssemblyLinearVelocity = 0xF8;
         inline uintptr_t CFrame = 0xC8;
         inline uintptr_t Flags = 0x1B6;
         inline uintptr_t Material = 0x0;
         inline uintptr_t Orientation = 0xC8;
         inline uintptr_t Owner = 0x210;
         inline uintptr_t Position = 0xEC;
         inline uintptr_t PrimitiveFlags = 0x1B6;
         inline uintptr_t Rotation = 0xC8;
         inline uintptr_t Size = 0x1BC;
         inline uintptr_t Validate = 0x6;
    }

    namespace PrimitiveFlags {
         inline uintptr_t Anchored = 0x2;
         inline uintptr_t CanCollide = 0x8;
         inline uintptr_t CanQuery = 0x20;
         inline uintptr_t CanTouch = 0x10;
    }

    namespace PrimitivePool {
         inline uintptr_t ArrayBase = 0x20;
    }

    namespace PrimitiveRecord {
         inline uintptr_t Stride = 0x30;
         inline uintptr_t Translation = 0x24;
    }

    namespace Properties {
         inline uintptr_t ClassDescriptor = 0x18;
         inline uintptr_t ClassName = 0x8;
         inline uintptr_t Properties = 0x78;
         inline uintptr_t PropertyDescriptorBitFlags = 0x8C;
         inline uintptr_t TType = 0x68;
         inline uintptr_t TTypeNumber = 0x30;
    }

    namespace PropertyDescriptor {
         inline uintptr_t CallbackStorage = 0x80;
         inline uintptr_t ScriptableMask = 0x10;
         inline uintptr_t TypeDescriptor = 0x68;
    }

    namespace Proto {
         inline uintptr_t code = 0x30;
         inline uintptr_t k = 0x28;
         inline uintptr_t sizecode = 0x98;
         inline uintptr_t sizek = 0xA8;
    }

    namespace ProximityPrompt {
         inline uintptr_t ActionText = 0xB0;
         inline uintptr_t Enabled = 0x136;
         inline uintptr_t HoldDuration = 0x120;
         inline uintptr_t KeyboardKeyCode = 0x124;
         inline uintptr_t MaxActivationDistance = 0x128;
         inline uintptr_t ObjectText = 0xD0;
         inline uintptr_t RequiresLineOfSight = 0x137;
    }

    namespace Render {
         inline uintptr_t RenderJobToView = 0x1D0;
         inline uintptr_t RenderViewToDevice = 0x8;
    }

    namespace RenderQueue {
         inline uintptr_t AlwaysOnTop = 0xD;
         inline uintptr_t AlwaysOnTopAdorns = 0xE;
         inline uintptr_t Decals = 0x2;
         inline uintptr_t Glass = 0x8;
         inline uintptr_t GlassTint = 0x7;
         inline uintptr_t OnTopReadOnlyDepth = 0xC;
         inline uintptr_t OnTopWithDepth = 0xB;
         inline uintptr_t Opaque = 0x0;
         inline uintptr_t OpaqueAdorns = 0x4;
         inline uintptr_t OpaqueCasters = 0x3;
         inline uintptr_t OpaqueWithAlpha = 0x5;
         inline uintptr_t Screen = 0xF;
         inline uintptr_t ScreenOnTopOfBlur = 0x10;
         inline uintptr_t Terrain = 0x1;
         inline uintptr_t Transparent = 0x9;
         inline uintptr_t TransparentCasters = 0xA;
         inline uintptr_t Water = 0x6;
    }

    namespace RenderView {
         inline uintptr_t LightingValid = 0x150;
         inline uintptr_t SkyboxValid = 0x28D;
    }

    namespace RobloxExtraSpace {
         inline uintptr_t Capabilities = 0x70;
         inline uintptr_t Continuations = 0x98;
         inline uintptr_t Identity = 0x48;
         inline uintptr_t Script = 0x60;
         inline uintptr_t Shared = 0x18;
         inline uintptr_t capabilities = 0x68;
         inline uintptr_t identity = 0x48;
         inline uintptr_t script = 0x58;
    }

    namespace ScriptContext {
         inline uintptr_t LuaState = 0x300;
         inline uintptr_t RequireBypass = 0x0;
         inline uintptr_t Resume = 0x8E0;
    }

    namespace Seat {
         inline uintptr_t Occupant = 0x218;
    }

    namespace SignalConnection {
         inline uintptr_t Enabled = 0x20;
         inline uintptr_t FunctionScriptSlotSelf = 0x18;
         inline uintptr_t Next = 0x10;
         inline uintptr_t SelfWeakFallback = 0x48;
         inline uintptr_t SlotWrapper = 0x30;
         inline uintptr_t SlotWrapperFallbackSelf = 0x40;
         inline uintptr_t SlotWrapperSelf = 0x38;
         inline uintptr_t WeakChain = 0x68;
         inline uintptr_t WeakChainNext = 0x8;
    }

    namespace SignalWeakObject {
         inline uintptr_t FunctionReference = 0x34;
         inline uintptr_t Pointer = 0x60;
         inline uintptr_t Thread = 0x28;
         inline uintptr_t WaitContainer = 0x50;
    }

    namespace Sky {
         inline uintptr_t MoonAngularSize = 0x244;
         inline uintptr_t MoonTextureId = 0xC8;
         inline uintptr_t SkyboxBk = 0xF8;
         inline uintptr_t SkyboxDn = 0x128;
         inline uintptr_t SkyboxFt = 0x158;
         inline uintptr_t SkyboxLf = 0x188;
         inline uintptr_t SkyboxOrientation = 0x238;
         inline uintptr_t SkyboxRt = 0x1B8;
         inline uintptr_t SkyboxUp = 0x1E8;
         inline uintptr_t StarCount = 0x248;
         inline uintptr_t SunAngularSize = 0x23C;
         inline uintptr_t SunTextureId = 0x218;
    }

    namespace SpecialMesh {
         inline uintptr_t MeshId = 0xF8;
         inline uintptr_t Offset = 0xB8;
         inline uintptr_t Scale = 0xC4;
         inline uintptr_t TextureId = 0x128;
    }

    namespace StatsItem {
         inline uintptr_t Value = 0xC8;
    }

    namespace SunRaysEffect {
         inline uintptr_t Enabled = 0xB0;
         inline uintptr_t Intensity = 0xB8;
         inline uintptr_t Spread = 0xBC;
    }

    namespace TString {
         inline uintptr_t hash = 0x10;
         inline uintptr_t len = 0x14;
    }

    namespace TaskScheduler {
         inline uintptr_t JobEnd = 0xD0;
         inline uintptr_t JobName = 0x18;
         inline uintptr_t JobStart = 0xC8;
         inline uintptr_t JobTypeName = 0xF8;
         inline uintptr_t Pointer = 0x8ABD728;
         inline uintptr_t ScriptContext = 0x440;
    }

    namespace Team {
         inline uintptr_t BrickColor = 0xB8;
         inline uintptr_t TeamColor = 0xB8;
    }

    namespace TechniqueArray {
         inline uintptr_t BeginOffset = 0x0;
         inline uintptr_t EndOffset = 0x8;
         inline uintptr_t EntryStride = 0x88;
    }

    namespace Terrain {
         inline uintptr_t GrassLength = 0x1F0;
         inline uintptr_t MaterialColors = 0x4B8;
         inline uintptr_t WaterColor = 0x1E0;
         inline uintptr_t WaterReflectance = 0x1F8;
         inline uintptr_t WaterTransparency = 0x1FC;
         inline uintptr_t WaterWaveSize = 0x200;
         inline uintptr_t WaterWaveSpeed = 0x204;
    }

    namespace TextButton {
         inline uintptr_t AutoButtonColor = 0x9C4;
         inline uintptr_t ContentText = 0xE08;
         inline uintptr_t Font = 0x1140;
         inline uintptr_t LineHeight = 0xF20;
         inline uintptr_t LocalizedText = 0xE08;
         inline uintptr_t MaxVisibleGraphemes = 0x114C;
         inline uintptr_t Modal = 0x9C5;
         inline uintptr_t RichText = 0xB88;
         inline uintptr_t Selected = 0x9C6;
         inline uintptr_t Text = 0xDF0;
         inline uintptr_t TextColor3 = 0xEA0;
         inline uintptr_t TextDirection = 0xFC0;
         inline uintptr_t TextScaled = 0x1016;
         inline uintptr_t TextSize = 0x1154;
         inline uintptr_t TextStrokeColor3 = 0x1134;
         inline uintptr_t TextStrokeTransparency = 0x1158;
         inline uintptr_t TextTransparency = 0x115C;
         inline uintptr_t TextTruncate = 0x1160;
         inline uintptr_t TextWrapped = 0x1018;
         inline uintptr_t TextXAlignment = 0x1164;
         inline uintptr_t TextYAlignment = 0xF68;
    }

    namespace TextLabel {
         inline uintptr_t ContentText = 0xB88;
         inline uintptr_t Font = 0xEC0;
         inline uintptr_t LineHeight = 0xCA0;
         inline uintptr_t LocalizedText = 0xB88;
         inline uintptr_t MaxVisibleGraphemes = 0xECC;
         inline uintptr_t RichText = 0xD9E;
         inline uintptr_t Text = 0xB88;
         inline uintptr_t TextColor3 = 0xEA8;
         inline uintptr_t TextDirection = 0xD40;
         inline uintptr_t TextScaled = 0xD96;
         inline uintptr_t TextSize = 0xED4;
         inline uintptr_t TextStrokeColor3 = 0xEB4;
         inline uintptr_t TextStrokeTransparency = 0xED8;
         inline uintptr_t TextTransparency = 0xEDC;
         inline uintptr_t TextTruncate = 0xEE0;
         inline uintptr_t TextWrapped = 0xD96;
         inline uintptr_t TextXAlignment = 0xEE4;
         inline uintptr_t TextYAlignment = 0xCE8;
    }

    namespace Tool {
         inline uintptr_t CanBeDropped = 0x4B8;
         inline uintptr_t Enabled = 0x4B9;
         inline uintptr_t Grip = 0x4AC;
         inline uintptr_t GripForward = 0x4A0;
         inline uintptr_t GripPos = 0x4AC;
         inline uintptr_t GripRight = 0x488;
         inline uintptr_t GripUp = 0x494;
         inline uintptr_t ManualActivationOnly = 0x4BA;
         inline uintptr_t RequiresHandle = 0x1D5;
         inline uintptr_t Tooltip = 0x468;
    }

    namespace UpVal {
         inline uintptr_t v = 0x18;
    }

    namespace Value {
         inline uintptr_t Value = 0xB8;
    }

    namespace VehicleSeat {
         inline uintptr_t MaxSpeed = 0x228;
         inline uintptr_t Occupant = 0x208;
         inline uintptr_t SteerFloat = 0x22C;
         inline uintptr_t ThrottleFloat = 0x188;
         inline uintptr_t Torque = 0x234;
         inline uintptr_t TurnSpeed = 0x238;
    }

    namespace VirtualTable {
         inline uintptr_t RaiseEventInvocation = 0x18;
    }

    namespace VisualEngine {
         inline uintptr_t Dimensions = 0xB10;
         inline uintptr_t FakeDataModel = 0xAF0;
         inline uintptr_t Pointer = 0x8351408;
         inline uintptr_t RenderView = 0xC30;
         inline uintptr_t ViewMatrix = 0x1B0;
    }

    namespace Workspace {
         inline uintptr_t CurrentCamera = 0x4B8;
         inline uintptr_t Raycast = 0x0;
         inline uintptr_t ReadOnlyGravity = 0x9F0;
         inline uintptr_t World = 0x410;
    }

    namespace World {
         inline uintptr_t FallenPartsDestroyHeight = 0x220;
         inline uintptr_t Gravity = 0x22C;
         inline uintptr_t Primitives = 0x2B0;
         inline uintptr_t WorldSteps = 0x728;
         inline uintptr_t worldStepsPerSec = 0x728;
    }

    namespace WorldRoot {
         inline uintptr_t FindPartOnRayDescriptorRva = 0x685F840;
         inline uintptr_t FindPartOnRayWithIgnoreListDescriptorRva = 0x685F850;
         inline uintptr_t FindPartOnRayWithWhitelistDescriptorRva = 0x685F860;
         inline uintptr_t RaycastBoundDesc = 0x80FA4C0;
         inline uintptr_t RaycastBoundFn = 0x80;
         inline uintptr_t RaycastBoundFunctionOffset = 0x80;
         inline uintptr_t RaycastCompleteObjectLocatorRva = 0x709CDD8;
         inline uintptr_t RaycastDescriptorRva = 0x8024FD0;
         inline uintptr_t RaycastDescriptorVtableRva = 0x6170040;
         inline uintptr_t RaycastTypeDescriptorRva = 0x7CADAE0;
    }

    namespace lua_State {
         inline uintptr_t base = 0x30;
         inline uintptr_t ci = 0x40;
         inline uintptr_t global = 0x28;
         inline uintptr_t gt = 0x78;
         inline uintptr_t stack = 0x20;
         inline uintptr_t status = 0x3;
         inline uintptr_t top = 0x18;
         inline uintptr_t userdata = 0x70;
    }

}
// clang-format on
