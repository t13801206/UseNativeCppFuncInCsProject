#include "pch.h"
#include "NativeFunc.h"
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

__declspec(dllexport) void Native::Max(int* src, int num, int* mx, int* mxIndex)
{
    *mx = src[0];
    *mxIndex = 0;
    std::cout << CV_VERSION << std::endl;

    for (int i = 0; i < num; i++)
    {
        if (src[i] > *mx)
        {
            *mxIndex = i;
			//*mxIndex = red_img.cols;

            *mx = src[i];
        }
    }
}

__declspec(dllexport) void Native::ImageProcess()
{
	
	cv::Mat red_img(cv::Size(640, 480), CV_8UC3, cv::Scalar(0, 0, 255));
	cv::Mat white_img(cv::Size(640, 480), CV_8UC3, cv::Scalar::all(255));
	cv::Mat black_img = cv::Mat::zeros(cv::Size(640, 480), CV_8UC3);

	// ê‘ÇÇ‡Ç∆Ç…êFÇïœÇ¶ÇÈ
	cv::Mat green_img = red_img.clone();
	green_img = cv::Scalar(0, 255, 0);

	cv::namedWindow("red image");
	cv::namedWindow("white image");
	cv::namedWindow("black image");
	cv::namedWindow("green image");
	cv::imshow("red image", red_img);
	cv::imshow("white image", white_img);
	cv::imshow("black image", black_img);
	cv::imshow("green image", green_img);
	cv::waitKey(0);
}
