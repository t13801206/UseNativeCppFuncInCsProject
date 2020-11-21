#include "pch.h"
#include "NativeFunc.h"

NATIVEFUNC_API void Native::Max(int* src, int num, int* mx, int* mxIndex)
{
    *mx = src[0];
    *mxIndex = 0;

    for (int i = 0; i < num; i++)
    {
        if (src[i] > *mx)
        {
            *mxIndex = i;
            *mx = src[i];
        }
    }
}