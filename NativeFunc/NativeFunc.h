#pragma once

namespace Native
{    
    //input:  num個のint配列 src
    //output: 最大値とそのインデックス      
    __declspec(dllexport) double EvalLaplaian(char* imageName);
    __declspec(dllexport) void Max(int* src, int num, int* mx, int* mxIndex);
    __declspec(dllexport) void ImageProcess();
}