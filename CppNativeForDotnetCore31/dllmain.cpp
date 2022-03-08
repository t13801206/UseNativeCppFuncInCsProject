// dllmain.cpp : DLL アプリケーションのエントリ ポイントを定義します。
#include "pch.h"
#include <iostream>
#include <opencv2/core.hpp>

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

void CheckOpenCV()
{
    std::cout << "OpenCV Version: " << CV_VERSION << std::endl;
}

void SendCommand(char* command, int commandLength)
{
    for (int i = 0; i < commandLength; i++)
    {
        std::cout << command[i] << std::endl;
    }
}