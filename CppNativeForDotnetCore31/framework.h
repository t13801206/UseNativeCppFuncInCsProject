#pragma once

#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
// Windows ヘッダー ファイル
#include <windows.h>

#define DllExport   __declspec( dllexport )

extern "C"
{
    DllExport void CheckOpenCV();
    DllExport void SendCommand(char*, int);
}
