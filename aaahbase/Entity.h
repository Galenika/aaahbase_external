#pragma once

class LocalPlayer {
public:
	~LocalPlayer();
	LocalPlayer();
	DWORD getLocalPlayer();
	int getTeamNum();
	int getFlags();
	int getMoveType();
	bool InAir();
	void ForceFullUpdate();
};

class Entity
{
public:
	Entity();
	~Entity();

	int getEntityTeamNum(int EntityList);
	bool getEntityDormantStatus(int EntityList);
	int getClassID(int entity);
	int getHealth(int entity);
};

extern LocalPlayer *pLocal;
extern Entity *pEntity;