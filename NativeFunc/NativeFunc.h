#pragma once
#ifdef NATIVEFUNC_EXPORTS
#define NATIVEFUNC_API __declspec(dllexport)
#else
#define NATIVEFUNC_API __declspec(dllimport)
#endif

namespace Native
{
    // num��int�z��src����A�ő�l�Ƃ��̃C���f�b�N�X��T���֐��ł�
    NATIVEFUNC_API void Max(int* src, int num, int* mx, int* mxIndex);
}