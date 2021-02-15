#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
	Mat srcMat = imread("0.jpg");
	Point pt,pt1,pt2;
	Rect rect;
	pt.x = 100;
	pt.y = 100;
	pt1.x = 50;
	pt1.y = 50;
	rect.x = 100;
	rect.y = 100;
	rect.width = 500;
	rect.height = 400;
	circle(srcMat, pt, 50, CV_RGB(255, 0, 0), 1, 8, 0);
	line(srcMat, pt1, pt2, CV_RGB(255, 0, 0), 1, 8, 0);
	rectangle(srcMat, rect, CV_RGB(255, 0, 0), 1, 8, 0);
	imshow("After Drawing", srcMat);
	waitKey(0);


}