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
    // �K�x�[�W�R���N�V������������邽�߂ɁApin_ptr���g���ČŒ肷��
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

    // pin_ptr:�}�l�[�W�h �N���X�̃A�h���X���A���}�l�[�W�h�֐��ɓn���Ƃ��ɁA�A���}�l�[�W�h�֐��Ăяo���̉������ɃA�h���X���\�z�O�ɕύX����Ȃ��悤�ɂ���ꍇ�ɕK�v
    // https://docs.microsoft.com/ja-jp/cpp/extensions/pin-ptr-cpp-cli?view=msvc-160
    // char* pStr = (char*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(imageName).ToPointer();
    // System::Runtime::InteropServices::Marshal::FreeHGlobal((IntPtr)pStr);
}
