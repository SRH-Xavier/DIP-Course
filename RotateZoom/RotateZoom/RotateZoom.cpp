//程序功能：旋转及放缩


#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	Mat dstMat;
	Mat srcMat = imread("0.jpg");

	//顺时针旋转30°，缩放尺度为2
	float angle = -30.0, scale = 0.5;
	//旋转中心为图像中心
	Point2f center(srcMat.cols*0.5, srcMat.rows*0.5);
	//获得变换矩阵
	const Mat affine_matrix = getRotationMatrix2D(center, angle, scale);
	warpAffine(srcMat, dstMat, affine_matrix, srcMat.size());

	imshow("srcMat", srcMat);
	imshow("dstMat", dstMat);
	waitKey(0);
}


