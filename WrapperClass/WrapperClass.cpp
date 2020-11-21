#include "WrapperClass.h"
#include "..\NativeFunc\NativeFunc.h"

void Wrapper::WrapperClass::Max(array<int>^ src, int num, int% mx, int% mxIndex)
{
    // ���������|�C���g
    // ���s���A�K�x�[�W�R���N�V��������Ȃ��悤�ɁApin_ptr���g���ČŒ肷��
    pin_ptr<int> psrc = &src[0];
    pin_ptr<int> pmx = &mx;
    pin_ptr<int> pMxIndex = &mxIndex;

    // ����֐����s
    Native::Max(psrc, num, pmx, pMxIndex);

    // ���������|�C���g
    // �Œ����
    psrc = nullptr;
    pmx = nullptr;
    pMxIndex = nullptr;
}