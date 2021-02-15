#include <opencv.hpp>
#include <math.h>

using namespace cv;
using namespace std;

int main()
{
	Mat srcMat = imread("0.jpg");
	Mat greyMat = imread("0.jpg", 0);
	Mat binaryMat;
	Mat inversedMat = 255 - greyMat;
	threshold(inversedMat, binaryMat,100, 255, THRESH_OTSU);

	Mat element = getStructuringElement(MORPH_RECT, Size(11,11));
	morphologyEx(binaryMat, binaryMat, MORPH_OPEN, element);

	vector<vector<Point>> contours;
	findContours(binaryMat, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);

	float rate[100];

	for (int i = 0; i < contours.size(); i++)
	{
		RotatedRect rect = minAreaRect(contours[i]);
		Point2f vtx[4];
		rect.points(vtx);

		float Y = sqrt((vtx[0].y - vtx[1].y) * (vtx[0].y - vtx[1].y) + (vtx[0].x - vtx[1].x) * (vtx[0].x - vtx[1].x));
		float X = sqrt((vtx[1].y - vtx[2].y) * (vtx[1].y - vtx[2].y) + (vtx[1].x - vtx[2].x) * (vtx[1].x - vtx[2].x));
		rate[i] = X / Y;

		if ((rate[i] >= 0.90) and (rate[i] <= 1.1))
		{
			for (int j = 0; j <= 3; j++)
			{
				line(srcMat, vtx[j], vtx[j < 3 ? j + 1 : 0], Scalar(0, 0, 255), 2, CV_AA);
			}
		}
	}
	imshow("srcMat", srcMat);

	waitKey(0);
	return 0;
}
