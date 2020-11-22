#include "WrapperClass.h"
#include "..\NativeFunc\NativeFunc.h"

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
