// dllmain.cpp : Defines the entry point for the DLL application.
#include "Includes.h"
DWORD WINAPI Main() {
    UnityResolve::Init(GetModuleHandle((const WCHAR*)L"GameAssembly.dll"), UnityResolve::Mode::Il2Cpp);
    fs::path p(".\\IL2Cpp-DumpedGame");
    if (p.empty()) {
        UnityResolve::DumpToFile(".\\IL2Cpp-DumpedGame");
        MessageBoxA(0, "Dumped Successfully!!!", "IL2CppInternalDumper", MB_OK | MB_ICONINFORMATION);
        exit(322);
    }
    else {
        exit(443);
    }
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Main, 0, 0, 0);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

