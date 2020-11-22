#include "WrapperClass.h"

Wrapper::WrapperClass::WrapperClass()
{
    _na0 = new Native::NativeOpenCvClass();
}

Wrapper::WrapperClass::~WrapperClass()
{
    delete _na0;
    _na0 = nullptr;
}

Wrapper::WrapperClass::!WrapperClass()
{
    this->~WrapperClass();
}

void Wrapper::WrapperClass::Max(array<int>^ src, int num, int% mx, int% mxIndex)
{
    // ガベージコレクションを回避するために、pin_ptrを使って固定する
    pin_ptr<int> psrc = &src[0];
    pin_ptr<int> pmx = &mx;
    pin_ptr<int> pMxIndex = &mxIndex;

    Native::Max(psrc, num, pmx, pMxIndex);

    psrc = nullptr;
    pmx = nullptr;
    pMxIndex = nullptr;
}

void Wrapper::WrapperClass::ImageProcess()
{
    Native::ImageProcess();
}

double Wrapper::WrapperClass::EvaluateImageBlur(String^ imageName)
{
    double score;
    pin_ptr<char> p_imageName;
    
    p_imageName = (char*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(imageName).ToPointer();
    score = _na0->EvaluateImageBlur(p_imageName);

    p_imageName = nullptr;

    return score;

    // pin_ptr:マネージド クラスのアドレスをアンマネージド関数に渡すときに、アンマネージド関数呼び出しの解決時にアドレスが予想外に変更されないようにする場合に必要
    // https://docs.microsoft.com/ja-jp/cpp/extensions/pin-ptr-cpp-cli?view=msvc-160
    // char* pStr = (char*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(imageName).ToPointer();
    // System::Runtime::InteropServices::Marshal::FreeHGlobal((IntPtr)pStr);
}
