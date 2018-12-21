#include "Includes.h"

LocalPlayer *pLocal = new LocalPlayer();

LocalPlayer::LocalPlayer() {}
LocalPlayer::~LocalPlayer() {}

DWORD LocalPlayer::getLocalPlayer() {
	return m->ReadMem<DWORD>(m->cDll.base + g_Offsets::Signatures::dwLocalPlayer);
}

int LocalPlayer::getTeamNum() {
	return m->ReadMem<int>(pLocal->getLocalPlayer() + g_Offsets::Netvars::m_iTeamNum);
}

int LocalPlayer::getFlags() {
	return m->ReadMem<int>(pLocal->getLocalPlayer() + g_Offsets::Netvars::m_fFlags);
}

int LocalPlayer::getMoveType() {
	return m->ReadMem<int>(pLocal->getLocalPlayer() + g_Offsets::Netvars::m_MoveType);
}

bool LocalPlayer::InAir() {
	return getFlags() == 256 || getFlags() == 258 || getFlags() == 260 || getFlags() == 262;
}

void LocalPlayer::ForceFullUpdate() {
	DWORD cState = m->ReadMem<DWORD>(m->eDll.base + g_Offsets::Signatures::dwClientState);
	m->WriteMem<int>(cState + 0x174, -1);
}

Entity *pEntity = new Entity();

Entity::Entity() {}
Entity::~Entity() {}

int Entity::getEntityTeamNum(int EntityList) {
	return m->ReadMem<int>(EntityList + g_Offsets::Netvars::m_iTeamNum);
}

bool Entity::getEntityDormantStatus(int EntityList) {
	return m->ReadMem<bool>(EntityList + g_Offsets::Signatures::m_bDormant);
}

int Entity::getClassID(int entity) {
	DWORD dwClientNetworkable = m->ReadMem<int>(entity + 0x8); // IClientNetworkable VTABLE Location
	DWORD dwGetClientClassFn = m->ReadMem<int>(dwClientNetworkable + 2 * 0x4); // Third function in the vtable /GetClientClass/
	DWORD dwEntityClientClass = m->ReadMem<int>(dwGetClientClassFn + 1); //pointer to ClientClass struct

	return m->ReadMem<int>(dwEntityClientClass + 0x14); // actual class id
}

int Entity::getHealth(int entity) {
	return  m->ReadMem<int>(entity + g_Offsets::Netvars::m_iHealth);
}