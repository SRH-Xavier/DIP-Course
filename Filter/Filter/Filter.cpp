//程序功能：中值滤波、均值滤波、高斯滤波


#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;
int main()
{
	//电脑无摄像头，用本地图片代替
	Mat medianMat, meanMat, gaussianMat;
	Mat srcMat = imread("0.jpg");

	//中值滤波
	int mediansize = 7;
	medianBlur(srcMat, medianMat, mediansize);
	//均值滤波
	Size blursize = Size(7, 7);
	blur(srcMat, meanMat, blursize);
	//高斯滤波
	double sigmaX = 1;
	double sigmaY = 1;
	Size Gaussiansize = Size(7, 7);
	GaussianBlur(srcMat, gaussianMat, Gaussiansize, sigmaX, sigmaY);

	imshow("原图 ", srcMat);
	imshow("中值滤波", medianMat);
	imshow("均值滤波", meanMat);
	imshow("高斯滤波", gaussianMat);

	waitKey(0);
	return 0;
}