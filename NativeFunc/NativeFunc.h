#pragma once
#ifdef NATIVEFUNC_EXPORTS
#define NATIVEFUNC_API __declspec(dllexport)
#else
#define NATIVEFUNC_API __declspec(dllimport)
#endif

namespace Native
{
    // num個のint配列srcから、最大値とそのインデックスを探す関数です
    NATIVEFUNC_API void Max(int* src, int num, int* mx, int* mxIndex);
}