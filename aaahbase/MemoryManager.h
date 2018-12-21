#pragma once
#include <Windows.h>
#include <TlHelp32.h>
#include <iostream>
#include <tchar.h>
#include "Variables.h"

struct Module {
	DWORD base;
	DWORD size;
};

class MemoryManager {
public:
	Module cDll;
	Module eDll;
	DWORD pID;
	static HANDLE hProc;

	bool attachProc(const char* procName) {
		HANDLE hPID = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
		PROCESSENTRY32 procEntry;
		procEntry.dwSize = sizeof(procEntry);
		const WCHAR* procNameCh;
		int numChar = MultiByteToWideChar(CP_ACP, 0, procName, -1, NULL, 0);
		procNameCh = new WCHAR[numChar];
		MultiByteToWideChar(CP_ACP, 0, procName, -1, (LPWSTR)procNameCh, numChar);
		do {
			if (!wcscmp(procEntry.szExeFile, procNameCh)) {
				pID = procEntry.th32ProcessID;
				CloseHandle(hPID);
				this->hProc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, this->pID);
				return true;
			}
		} while (Process32Next(hPID, &procEntry));
		CloseHandle(hPID);
		return false;
	}

	Module getModule(DWORD processID, const char* moduleName) {
		DWORD_PTR dwModuleBaseAddress = 0;
		Module result;

		HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, processID);
		if (hSnapshot != INVALID_HANDLE_VALUE) {
			MODULEENTRY32 ModuleEntry32;
			ModuleEntry32.dwSize = sizeof(MODULEENTRY32);
			if (Module32First(hSnapshot, &ModuleEntry32)) {
				do {
					std::string moduleNameString(moduleName);
					std::wstring moduleNameWideString(moduleNameString.begin(), moduleNameString.end());
					if (_tcsicmp(ModuleEntry32.szModule, moduleNameWideString.c_str()) == 0)
					{
						dwModuleBaseAddress = (DWORD_PTR)ModuleEntry32.modBaseAddr;
						result.base = dwModuleBaseAddress;
						result.size = ModuleEntry32.modBaseSize;
						break;
					}
				} while (Module32Next(hSnapshot, &ModuleEntry32));
			}
			CloseHandle(hSnapshot);
		}
		return result;
	}

	template <class c>
	c ReadMem(DWORD dwAddress) {
		c val;
		ReadProcessMemory(hProc, (LPVOID)dwAddress, &val, sizeof(c), NULL);
		return val;
	}
	template <class c>
	BOOL WriteMem(DWORD dwAddress, c valToWrite) {
		return WriteProcessMemory(hProc, (LPVOID)dwAddress, &valToWrite, sizeof(c), NULL);
	}
	
	MemoryManager();
	~MemoryManager();
};

