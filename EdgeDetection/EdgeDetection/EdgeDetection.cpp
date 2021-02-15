//程序功能：X、Y方向边缘提取


#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;
int main()
{
	Mat dx, dy, absx, absy;
	Mat srcMat = imread("0.jpg");		//无摄像头，采用本地图片代替

	Sobel(srcMat, dx, CV_16S, 1, 0, 3);
	convertScaleAbs(dx, absx);	//图像增强
	Sobel(srcMat, dy, CV_16S, 0, 1, 3);
	convertScaleAbs(dy, absy);

	imshow("原图", srcMat);
	imshow("X方向上的边缘提取", absx);
	imshow("Y方向上的边缘提取", absy);

	waitKey(0);
	return 0;
}