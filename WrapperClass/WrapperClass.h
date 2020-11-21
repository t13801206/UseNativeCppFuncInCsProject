#pragma once
using namespace System;

namespace Wrapper {

    public ref class WrapperClass
    {
    public:
        void Max(array<int>^ src, int num, int% mx, int% mxIndex);
    };
}
