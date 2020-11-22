#include "pch.h"
#include "NativeOpenCvClass.h"
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>

#define SIZE 255

double Native::NativeOpenCvClass::EvaluateImageBlur(char* imageName)
{
	cv::Mat image, image_out;

	image = cv::imread(imageName, cv::ImreadModes::IMREAD_GRAYSCALE);

	if (image.empty())
		return -1;

	double* minVal = new double[SIZE];
	double* maxVal = new double[SIZE];
	int* minIdx = new int[SIZE];
	int* maxIdx = new int[SIZE];
	double score = -1.0;

	cv::minMaxIdx(image, minVal, maxVal, minIdx, maxIdx);
	std::cout << "before: " << *minVal << ",(" << *minIdx << ")," << *maxVal << ",(" << *maxIdx << ")" << std::endl;
	Laplacian(image, image_out, CV_32F);
	cv::minMaxIdx(image_out, minVal, maxVal, minIdx, maxIdx);
	std::cout << "after:  " << *minVal << ",(" << *minIdx << ")," << *maxVal << ",(" << *maxIdx << ")" << std::endl;
	
	score = *minVal * *maxVal;
	
	delete[] minVal;
	delete[] maxVal;
	delete[] minIdx;
	delete[] maxIdx;

	return score;
}
