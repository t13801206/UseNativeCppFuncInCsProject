#pragma once
using namespace System;
#include "..\NativeFunc\NativeFunc.h"
#include "..\NativeFunc\NativeOpenCvClass.h"

namespace Wrapper
{
	public ref class WrapperClass
	{
	private:
		Native::NativeOpenCvClass* _na0;
	public:
		WrapperClass();
		~WrapperClass();
		!WrapperClass();
		void Max(array<int>^ src, int num, int% mx, int% mxIndex);
		void ImageProcess();
		double EvaluateImageBlur(String^ imageName);
	};
}
