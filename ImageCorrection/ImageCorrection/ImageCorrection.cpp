//程序功能：图像矫正


#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;
int main()
{
	Mat srcMat = imread("0.jpg");
	Mat dstMat, grayMat, binaryMat;

	cvtColor(srcMat, grayMat, CV_RGB2GRAY);
	threshold(grayMat, binaryMat, 0, 255, THRESH_OTSU);

	int width, height;
	width = srcMat.cols;
	height = srcMat.rows;
	int i, left, right, up, down;
	for (i = 0; i < width - 1; i++)
	{
		if (binaryMat.at<uchar>(i, 0) == 255 && binaryMat.at<uchar>(i + 1, 0) != 255)
		{
			left = i + 1;
		}
		if (binaryMat.at<uchar>(i, width - 1) == 255 && binaryMat.at<uchar>(i + 1, width - 1) != 255)
		{
			right = i + 1;   
		}
	}

	for (i = 0; i < height - 1; i++)
	{
		if (binaryMat.at<uchar>(1, i) == 255 && binaryMat.at<uchar>(1, i + 1) != 255)
		{
			up = i + 1; 
		}
		if (binaryMat.at<uchar>(height - 1, i) == 255 && binaryMat.at<uchar>(height - 1, i + 1) != 255)
		{
			down = i + 1;
		}
	}
	//变换前的四点坐标
	const Point2f src_pt[] = {
		Point2f(up,1),
		Point2f(down,height - 1),
		Point2f(0,left),
		Point2f(width - 1,right) };
	//变换后的四点坐标
	const Point2f dst_pt[] = {
		Point2f(0,0),
		Point2f(width - 1,height - 1),
		Point2f(0,height - 1),
		Point2f(width - 1,0) };
	//变换矩阵
	Mat perspective_matrix = getPerspectiveTransform(src_pt, dst_pt);

	warpPerspective(srcMat, dstMat, perspective_matrix, srcMat.size());

	imshow("srcMat", srcMat);
	imshow("dstMat", dstMat);

	waitKey(0);
	return 0;
}
