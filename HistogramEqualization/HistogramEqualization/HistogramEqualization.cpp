// 三通道直方图均衡


#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	Mat srcMat, dstMat;
	srcMat = imread("0.jpg");

	Mat Array[3];
	split(srcMat, Array);

	for (int i = 0; i < 3; i++)
	{
		equalizeHist(Array[i], Array[i]);
	}

	merge(Array, 3, dstMat);

	imshow("srcMat", srcMat);
	imshow("dstMat", dstMat);

	waitKey(0);
	return 0;
}