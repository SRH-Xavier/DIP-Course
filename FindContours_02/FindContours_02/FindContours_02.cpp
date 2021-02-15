#include <opencv.hpp>
#include <math.h>

using namespace cv;
using namespace std;

int main()
{
	Mat srcMat = imread("0.jpg");
	Mat greyMat = imread("0.jpg", 0);
	Mat binaryMat;
	threshold(greyMat, binaryMat, 100, 255, THRESH_OTSU);
	Mat element = getStructuringElement(MORPH_RECT, Size(13, 13));
	morphologyEx(binaryMat, binaryMat, MORPH_OPEN, element);

	vector<vector<Point>> contours;
	findContours(binaryMat, contours, CV_RETR_LIST, CV_CHAIN_APPROX_NONE);

	for (int i = 0; i < contours.size(); i++)
	{
		RotatedRect rect = minAreaRect(contours[i]);
		Point2f vtx[4];
		rect.points(vtx);

		for (int j = 0; j <= 3; j++)
		{
			line(srcMat, vtx[j], vtx[j < 3 ? j + 1 : 0], Scalar(0, 0, 255), 2, CV_AA);
		}
	}
	imshow("srcMat", srcMat);

	waitKey(0);
	return 0;
}
