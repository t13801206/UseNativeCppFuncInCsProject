#pragma once

namespace Native
{
    class __declspec(dllexport) NativeOpenCvClass
    {
    public:
        double EvaluateImageBlur(char* imageName);
    };
}