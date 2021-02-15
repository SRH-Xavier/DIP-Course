#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
	Mat binaryMat, labelMat, stateMat, centerMat,openingMat;
	Mat srcMat = imread("0.jpg", 0);
	bitwise_not(srcMat, srcMat);  //图像取非
	threshold(srcMat, binaryMat, 0, 255, THRESH_OTSU);
	Mat element = getStructuringElement(MORPH_RECT, Size(20, 20));
	morphologyEx(binaryMat, openingMat, MORPH_OPEN, element);

	int Number = connectedComponentsWithStats(openingMat, labelMat, stateMat, centerMat, 8, CV_32S);
	cout << "圆点个数=" << Number - 1 << endl;		//除去背景外的连通域值为圆点数

	for (int i = 1 ; i < Number; i++)
	{
		Rect bbx;
		bbx.x = stateMat.at<int>(i, 0);
		bbx.y = stateMat.at<int>(i, 1);
		bbx.width = stateMat.at<int>(i, 2);
		bbx.height = stateMat.at<int>(i, 3);
		rectangle(binaryMat, bbx, CV_RGB(255, 255, 255), 1, 8, 0);
	}

	imshow("frame", srcMat);
	imshow("binaryMat", binaryMat);
	waitKey(0);
	return 0;
}