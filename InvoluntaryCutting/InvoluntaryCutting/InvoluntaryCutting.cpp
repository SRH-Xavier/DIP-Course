//程序功能：不自主裁切的图像旋转


#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main()
{
	Mat srcMat = imread("0.jpg");
	Mat dstMat;

	float angle = -15, scale = 1;
	Point2f center(srcMat.cols/2.0, srcMat.rows/2.0);
	Mat affine_matrix = getRotationMatrix2D(center, angle, scale);
	//获取外界四边形
	Rect bbox = RotatedRect(center, srcMat.size(), angle).boundingRect();
	//调整放射矩阵参数
	affine_matrix.at<double>(0, 2) += bbox.width / 2.0 - center.x;
	affine_matrix.at<double>(1, 2) += bbox.height / 2.0 - center.y;
	//仿射变换
	warpAffine(srcMat, dstMat, affine_matrix, bbox.size());
	imshow("srcMat", srcMat);
	imshow("dstMat", dstMat);

	waitKey(0);
	return 0;
}
