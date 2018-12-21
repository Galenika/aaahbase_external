#pragma once
#include <cstdint>
namespace g_Offsets {
	namespace Netvars {
		constexpr ptrdiff_t cs_gamerules_data = 0x0;
		constexpr ptrdiff_t m_ArmorValue = 0xB324;
		constexpr ptrdiff_t m_Collision = 0x31C;
		constexpr ptrdiff_t m_CollisionGroup = 0x474;
		constexpr ptrdiff_t m_Local = 0x2FBC;
		constexpr ptrdiff_t m_MoveType = 0x25C;
		constexpr ptrdiff_t m_OriginalOwnerXuidHigh = 0x31B4;
		constexpr ptrdiff_t m_OriginalOwnerXuidLow = 0x31B0;
		constexpr ptrdiff_t m_SurvivalGameRuleDecisionTypes = 0x1318;
		constexpr ptrdiff_t m_SurvivalRules = 0xCF0;
		constexpr ptrdiff_t m_aimPunchAngle = 0x302C;
		constexpr ptrdiff_t m_aimPunchAngleVel = 0x3038;
		constexpr ptrdiff_t m_bBombPlanted = 0x99D;
		constexpr ptrdiff_t m_bFreezePeriod = 0x20;
		constexpr ptrdiff_t m_bGunGameImmunity = 0x3928;
		constexpr ptrdiff_t m_bHasDefuser = 0xB334;
		constexpr ptrdiff_t m_bHasHelmet = 0xB318;
		constexpr ptrdiff_t m_bInReload = 0x3285;
		constexpr ptrdiff_t m_bIsDefusing = 0x3914;
		constexpr ptrdiff_t m_bIsQueuedMatchmaking = 0x74;
		constexpr ptrdiff_t m_bIsScoped = 0x390A;
		constexpr ptrdiff_t m_bIsValveDS = 0x75;
		constexpr ptrdiff_t m_bSpotted = 0x93D;
		constexpr ptrdiff_t m_bSpottedByMask = 0x980;
		constexpr ptrdiff_t m_clrRender = 0x70;
		constexpr ptrdiff_t m_dwBoneMatrix = 0x26A8;
		constexpr ptrdiff_t m_fAccuracyPenalty = 0x3304;
		constexpr ptrdiff_t m_fFlags = 0x104;
		constexpr ptrdiff_t m_flC4Blow = 0x2990;
		constexpr ptrdiff_t m_flDefuseCountDown = 0x29AC;
		constexpr ptrdiff_t m_flDefuseLength = 0x29A8;
		constexpr ptrdiff_t m_flFallbackWear = 0x31C0;
		constexpr ptrdiff_t m_flFlashDuration = 0xA3E0;
		constexpr ptrdiff_t m_flFlashMaxAlpha = 0xA3DC;
		constexpr ptrdiff_t m_flNextPrimaryAttack = 0x3218;
		constexpr ptrdiff_t m_flTimerLength = 0x2994;
		constexpr ptrdiff_t m_hActiveWeapon = 0x2EF8;
		constexpr ptrdiff_t m_hMyWeapons = 0x2DF8;
		constexpr ptrdiff_t m_hObserverTarget = 0x3388;
		constexpr ptrdiff_t m_hOwner = 0x29CC;
		constexpr ptrdiff_t m_hOwnerEntity = 0x14C;
		constexpr ptrdiff_t m_iAccountID = 0x2FC8;
		constexpr ptrdiff_t m_iClip1 = 0x3244;
		constexpr ptrdiff_t m_iCompetitiveRanking = 0x1A84;
		constexpr ptrdiff_t m_iCompetitiveWins = 0x1B88;
		constexpr ptrdiff_t m_iCrosshairId = 0xB390;
		constexpr ptrdiff_t m_iEntityQuality = 0x2FAC;
		constexpr ptrdiff_t m_iFOV = 0x31E4;
		constexpr ptrdiff_t m_iFOVStart = 0x31E8;
		constexpr ptrdiff_t m_iGlowIndex = 0xA3F8;
		constexpr ptrdiff_t m_iHealth = 0x100;
		constexpr ptrdiff_t m_iItemDefinitionIndex = 0x2FAA;
		constexpr ptrdiff_t m_iItemIDHigh = 0x2FC0;
		constexpr ptrdiff_t m_iObserverMode = 0x3374;
		constexpr ptrdiff_t m_iShotsFired = 0xA370;
		constexpr ptrdiff_t m_iState = 0x3238;
		constexpr ptrdiff_t m_iTeamNum = 0xF4;
		constexpr ptrdiff_t m_lifeState = 0x25F;
		constexpr ptrdiff_t m_nFallbackPaintKit = 0x31B8;
		constexpr ptrdiff_t m_nFallbackSeed = 0x31BC;
		constexpr ptrdiff_t m_nFallbackStatTrak = 0x31C4;
		constexpr ptrdiff_t m_nForceBone = 0x268C;
		constexpr ptrdiff_t m_nTickBase = 0x342C;
		constexpr ptrdiff_t m_rgflCoordinateFrame = 0x444;
		constexpr ptrdiff_t m_szCustomName = 0x303C;
		constexpr ptrdiff_t m_szLastPlaceName = 0x35B0;
		constexpr ptrdiff_t m_thirdPersonViewAngles = 0x31D8;
		constexpr ptrdiff_t m_vecOrigin = 0x138;
		constexpr ptrdiff_t m_vecVelocity = 0x114;
		constexpr ptrdiff_t m_vecViewOffset = 0x108;
		constexpr ptrdiff_t m_viewPunchAngle = 0x3020;
	}
	namespace Signatures {
		constexpr ptrdiff_t clientstate_choked_commands = 0x4CB0;
		constexpr ptrdiff_t clientstate_delta_ticks = 0x174;
		constexpr ptrdiff_t clientstate_last_outgoing_command = 0x4CAC;
		constexpr ptrdiff_t clientstate_net_channel = 0x9C;
		constexpr ptrdiff_t convar_name_hash_table = 0x2F0F8;
		constexpr ptrdiff_t dwClientState = 0x58BCFC;
		constexpr ptrdiff_t dwClientState_GetLocalPlayer = 0x180;
		constexpr ptrdiff_t dwClientState_IsHLTV = 0x4CC8;
		constexpr ptrdiff_t dwClientState_Map = 0x28C;
		constexpr ptrdiff_t dwClientState_MapDirectory = 0x188;
		constexpr ptrdiff_t dwClientState_MaxPlayer = 0x310;
		constexpr ptrdiff_t dwClientState_PlayerInfo = 0x5240;
		constexpr ptrdiff_t dwClientState_State = 0x108;
		constexpr ptrdiff_t dwClientState_ViewAngles = 0x4D10;
		constexpr ptrdiff_t dwEntityList = 0x4CCDBFC;
		constexpr ptrdiff_t dwForceAttack = 0x30FF2A0;
		constexpr ptrdiff_t dwForceAttack2 = 0x30FF2AC;
		constexpr ptrdiff_t dwForceBackward = 0x30FF2E8;
		constexpr ptrdiff_t dwForceForward = 0x30FF2F4;
		constexpr ptrdiff_t dwForceJump = 0x5170DB0;
		constexpr ptrdiff_t dwForceLeft = 0x30FF30C;
		constexpr ptrdiff_t dwForceRight = 0x30FF300;
		constexpr ptrdiff_t dwGameDir = 0x630E70;
		constexpr ptrdiff_t dwGameRulesProxy = 0x51E30E4;
		constexpr ptrdiff_t dwGetAllClasses = 0xCE1964;
		constexpr ptrdiff_t dwGlobalVars = 0x58BA00;
		constexpr ptrdiff_t dwGlowObjectManager = 0x520DA28;
		constexpr ptrdiff_t dwInput = 0x5118990;
		constexpr ptrdiff_t dwInterfaceLinkList = 0x89E154;
		constexpr ptrdiff_t dwLocalPlayer = 0xCBD6B4;
		constexpr ptrdiff_t dwMouseEnable = 0xCC3200;
		constexpr ptrdiff_t dwMouseEnablePtr = 0xCC31D0;
		constexpr ptrdiff_t dwPlayerResource = 0x30FD65C;
		constexpr ptrdiff_t dwRadarBase = 0x510293C;
		constexpr ptrdiff_t dwSensitivity = 0xCC309C;
		constexpr ptrdiff_t dwSensitivityPtr = 0xCC3070;
		constexpr ptrdiff_t dwSetClanTag = 0x89590;
		constexpr ptrdiff_t dwViewMatrix = 0x4CBF614;
		constexpr ptrdiff_t dwWeaponTable = 0x5119454;
		constexpr ptrdiff_t dwWeaponTableIndex = 0x323C;
		constexpr ptrdiff_t dwYawPtr = 0xCC2E60;
		constexpr ptrdiff_t dwZoomSensitivityRatioPtr = 0xCC80A0;
		constexpr ptrdiff_t dwbSendPackets = 0xD20EA;
		constexpr ptrdiff_t dwppDirect3DDevice9 = 0xA3FC0;
		constexpr ptrdiff_t interface_engine_cvar = 0x3E9EC;
		constexpr ptrdiff_t m_bDormant = 0xED;
		constexpr ptrdiff_t m_pStudioHdr = 0x294C;
		constexpr ptrdiff_t m_pitchClassPtr = 0x5102BF0;
		constexpr ptrdiff_t m_yawClassPtr = 0xCC2E60;
		constexpr ptrdiff_t model_ambient_min = 0x58ED1C;
	}
}