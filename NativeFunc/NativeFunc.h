#pragma once

//#ifdef NATIVEFUNC_EXPORTS
//#define NATIVEFUNC_API __declspec(dllexport)
//#else
//#define NATIVEFUNC_API __declspec(dllimport)
//#endif

namespace Native
{    
    //input:  num��int�z�� src
    //output: �ő�l�Ƃ��̃C���f�b�N�X      
    __declspec(dllexport) void Max(int* src, int num, int* mx, int* mxIndex);
    __declspec(dllexport) void ImageProcess();
}