#pragma once

namespace Native
{    
    //input:  num��int�z�� src
    //output: �ő�l�Ƃ��̃C���f�b�N�X      
    __declspec(dllexport) double EvalLaplaian(char* imageName);
    __declspec(dllexport) void Max(int* src, int num, int* mx, int* mxIndex);
    __declspec(dllexport) void ImageProcess();
}