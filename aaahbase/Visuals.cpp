#include "Includes.h"

Visuals *pVisuals = new Visuals();

void Visuals::Chams() {
	while (true) {
		Color obj;

		std::this_thread::sleep_for(std::chrono::milliseconds(25));

		if (g_Variables::Visuals::Chams) {
			for (int i = 1; i < 64; i++) {
				int dwEntity = m->ReadMem<int>(m->cDll.base + g_Offsets::Signatures::dwEntityList + i * 0x10);

				if (pEntity->getEntityDormantStatus(dwEntity))
					continue;

				int pEntTeam = pEntity->getEntityTeamNum(dwEntity);

				if (pEntTeam == pLocal->getTeamNum())
					continue;

				// colors don't work for some reason, gonna fix whenever i have time
				obj.r = g_Variables::Visuals::ChamsColor[0];
				obj.g = g_Variables::Visuals::ChamsColor[1];
				obj.b = g_Variables::Visuals::ChamsColor[2];
				obj.a = 255;

				m->WriteMem<Color>(dwEntity + 0x70, obj);
			}
		}
	}
}

void Visuals::noFlash() {
	while (true) {
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
		m->WriteMem<float>(pLocal->getLocalPlayer() + g_Offsets::Netvars::m_flFlashDuration, g_Variables::Visuals::FlashAlpha);
	}
}