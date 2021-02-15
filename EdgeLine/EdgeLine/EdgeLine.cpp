//程序功能：画出两条边缘直线


#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main()
{
	Mat srcMat = imread("0.jpg"), cannyMat, lineMat;
	Canny(srcMat, cannyMat, 100, 200, 3);
	HoughLines(cannyMat, lineMat, 1, CV_PI / 180, 100);
	for (int i = 0; i < lineMat.rows; i++)
	{
		float rho = lineMat.at<Vec2f>(i)[0], theta = lineMat.at<Vec2f>(i)[1];
		Point pt1, pt2;
		double a = cos(theta), b = sin(theta);
		double x0 = a * rho, y0 = b * rho;
		pt1.x = saturate_cast<int>(x0 + 1000 * (-b));
		pt1.y = saturate_cast<int>(y0 + 1000 * (a));
		pt2.x = saturate_cast<int>(x0 - 1000 * (-b));
		pt2.y = saturate_cast<int>(y0 - 1000 * (a));
		line(srcMat, pt1, pt2, Scalar(255, 0, 255), 1, CV_AA);
	}

	imshow("srcMat", srcMat);
	waitKey(0);

}