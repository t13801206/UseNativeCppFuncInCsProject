#include "WrapperClass.h"
#include "..\NativeFunc\NativeFunc.h"

void Wrapper::WrapperClass::Max(array<int>^ src, int num, int% mx, int% mxIndex)
{
    // ★ここがポイント
    // 実行中、ガベージコレクションされないように、pin_ptrを使って固定する
    pin_ptr<int> psrc = &src[0];
    pin_ptr<int> pmx = &mx;
    pin_ptr<int> pMxIndex = &mxIndex;

    // 自作関数実行
    Native::Max(psrc, num, pmx, pMxIndex);

    // ★ここがポイント
    // 固定解除
    psrc = nullptr;
    pmx = nullptr;
    pMxIndex = nullptr;
}