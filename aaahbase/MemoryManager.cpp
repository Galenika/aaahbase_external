#include "MemoryManager.h"
HANDLE MemoryManager::hProc;
MemoryManager::MemoryManager() {
	this->hProc = NULL;
	this->pID = NULL;
	try {
		if (!attachProc("csgo.exe")) 
			throw 1;
		this->cDll = getModule(pID, "client_panorama.dll");
		this->eDll = getModule(pID, "engine.dll");
		g_Variables::csgowindow = true;
	}
	catch (...) {
		MessageBoxA(NULL, "Couldn't attach to CS:GO. Maybe the process is not running?", "'AAAHBASE EXTERNAL'", MB_ICONSTOP | MB_OK);
		g_Variables::csgowindow = false;
	}
}

MemoryManager::~MemoryManager() {
	CloseHandle(this->hProc);

}