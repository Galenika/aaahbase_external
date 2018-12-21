#include "Includes.h"

void Misc::Bhop() {
	while (true) {
		if (!g_Variables::Misc::Bhop)
			continue;
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
		if (GetAsyncKeyState(VK_SPACE))
			if (!pLocal->InAir())
				m->WriteMem<int>(m->cDll.base + g_Offsets::Signatures::dwForceJump, 6);
	}
}

Misc *pMisc = new Misc();