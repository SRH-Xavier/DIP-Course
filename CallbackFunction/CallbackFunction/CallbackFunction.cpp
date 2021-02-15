#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

string WindowName = "binaryMat";

void threshold_Mat(int th, void* data)
{
	Mat src = *(Mat*)(data);
	Mat dst;
	threshold(src, dst, th, 255, 0);
	imshow(WindowName, dst);
}

int main()
{
	Mat srcMat;
	Mat gryMat;
	int lowth = 30;
	int maxth = 255;
	
	srcMat = imread("0.jpg");
	if (!srcMat.data)
	{
		cout << "Í¼ÏñÔØÈëÊ§°Ü£¡" << endl;
		return 0;
	}
	cvtColor(srcMat, gryMat, CV_BGR2GRAY);
	imshow(WindowName, gryMat);
	createTrackbar("threshold", WindowName, &lowth, maxth, threshold_Mat, &gryMat);
	waitKey(0);

}