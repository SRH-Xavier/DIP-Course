#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
	Mat srcMat = imread("0.jpg", 0);		
	Mat binaryMat, erodeMat, dilateMat, openingMat, closingMat;
	threshold(srcMat, binaryMat, 0, 255, THRESH_OTSU);		//二值图
	Mat element = getStructuringElement(MORPH_RECT, Size(3, 3));		
	erode(binaryMat, erodeMat, element);		//腐蚀
	dilate(binaryMat, dilateMat, element);	//膨胀
	morphologyEx(binaryMat, openingMat, MORPH_OPEN, element);	//开运算
	morphologyEx(binaryMat, closingMat, MORPH_CLOSE, element);	//闭运算

	imshow("frame", srcMat);
	imshow("binaryMat", binaryMat);
	imshow("erode", erodeMat);
	imshow("dilate", dilateMat);
	imshow("opening", openingMat);
	imshow("closing", closingMat);
	//如果结果窗口处于屏幕外 可用ImageWatch查看

	waitKey(0);
	return 0;
}