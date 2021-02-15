#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
	Mat binaryMat, labelMat, stateMat, centerMat;
	Mat srcMat = imread("0.jpg", 0);
	bitwise_not(srcMat, srcMat);
	threshold(srcMat, binaryMat, 0, 255, THRESH_OTSU);
	Mat element = getStructuringElement(MORPH_ELLIPSE, Size(5, 5));
	morphologyEx(binaryMat, binaryMat, MORPH_OPEN, element);
	int Number = connectedComponentsWithStats(binaryMat, labelMat, stateMat, centerMat, 8, CV_32S);
	
	int count = 0; 
	for (int i = 1; i < Number; i++)
	{
		if ((stateMat.at <int>(i, 2) < 50) or (stateMat.at <int>(i, 3) < 50))
			continue;
		else
			count++;
		Rect bbx;
		bbx.x = stateMat.at<int>(i, 0);
		bbx.y = stateMat.at<int>(i, 1);
		bbx.width = stateMat.at<int>(i, 2);
		bbx.height = stateMat.at<int>(i, 3);
		rectangle(binaryMat, bbx, CV_RGB(255, 255, 255), 1, 8, 0);

	}

	cout << "回形针总数= " << count << endl;  
	imshow("frame", srcMat);
	imshow("binaryMat", binaryMat);
	waitKey(0);
	return 0;
}