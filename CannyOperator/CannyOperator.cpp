//程序功能：canny算子中值滤波


#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;
int main()
{
	Mat srcMat = imread("0.jpg");		// 电脑没有摄像头，采用本地图片代替
	Mat dxMat, dyMat, canny1, canny2;
	medianBlur(srcMat, srcMat, 3);		
	cvtColor(srcMat, srcMat, COLOR_BGR2GRAY);		

	Sobel(srcMat, dxMat, CV_16S, 1, 0, 3, 1, 1);	
	Sobel(srcMat, dyMat, CV_16S, 0, 1, 3, 1, 1);
	Canny(dxMat, dyMat, canny1, 3, 9);
	Canny(srcMat, canny2, 3, 9, 3);

	imshow("canny1", canny1);
	imshow("canny2", canny2);

	waitKey(0);
	return 0;
}