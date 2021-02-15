#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;

int cellsize = 16;
int nAngle = 8;

float O_Distance(float * a, float * b, int n);
int calHOG(Mat src, float * hist, int nAngle, int cellSize);


int main()
{
	Mat objMat = imread("0.jpg", 0);
	Mat srcMat = imread("1.jpg", 0);
	Mat dstMat;

	srcMat.copyTo(dstMat);
	int nAngle = 8;
	int cellSize = 16;
	int nX = objMat.cols / cellSize;
	int nY = objMat.rows / cellSize;

	int bins = nX * nY*nAngle;

	float * obj_hist = new float[bins];
	memset(obj_hist, 0, sizeof(float)*bins);

	int reCode = 0;
	reCode = calHOG(objMat, obj_hist, nAngle, cellSize);
	if (reCode != 0) {
		return -1;
	}

	Rect rect;
	Mat fraMat;
	Point dstposition;
	int cnt = 0;
	float distance, dist;
	Mat distanceMat = Mat(srcMat.size(), CV_32FC1, Scalar(255,0,0));
	for (int i = 0; i < srcMat.rows - objMat.rows + 1; i++)
	{
		for (int j = 0; j < srcMat.cols - objMat.cols + 1; j++)
		{
			float * fra_hist = new float[bins];
			memset(fra_hist, 0, sizeof(float)*bins);
			rect = Rect(j, i, objMat.cols, objMat.rows);
			fraMat = srcMat(rect);

			calHOG(fraMat, fra_hist, nAngle, cellSize);
			dist = O_Distance(obj_hist, fra_hist, bins);
			distanceMat.at<float>(i, j) = dist;

			if (cnt == 0)
			{
				distance = dist;
				dstposition.x = j;  
				dstposition.y = i;
				cnt++;
			}
			else 
			{
				if (dist < distance)
				{
					distance = dist;
					dstposition.x = j;  dstposition.y = i;
				}
			}
			delete[] fra_hist;
		}
	}

	rectangle(dstMat, dstposition, Point(dstposition.x + objMat.cols, dstposition.y + objMat.rows), Scalar(255, 0, 0), 2, 8, 0);
	delete[] obj_hist;
	destroyAllWindows();

	imshow("×·×Ù¶¨Î»Í¼Ïñ", dstMat);

	waitKey(0);
	return 0;

}


int calHOG(Mat src, float * hist, int nAngle, int cellSize)
{
	Mat gx, gy;
	Mat mag, angle;
	Sobel(src, gx, CV_32F, 1, 0, 1);
	Sobel(src, gy, CV_32F, 0, 1, 1);
	cartToPolar(gx, gy, mag, angle, true);
	int nX = src.cols / cellsize;
	int nY = src.rows / cellsize;
	for (int i = 0; i < nY; i++)
	{
		for (int j = 0; j < nX; j++)
		{
			Mat roiMat;
			Mat roiMag;
			Mat roiAgl;
			Rect roi = Rect(j*cellsize, i*cellsize, cellsize, cellsize);
			roi.x = j * cellsize;
			roi.y = i * cellsize;

			roiMat = src(roi);
			roiMag = mag(roi);
			roiAgl = angle(roi);

			int head = (i*nX + j)*nAngle;
			for (int n = 0; n < roiMat.rows; n++)
			{
				for (int m = 0; m < roiMat.cols; m++)
				{
					hist[head + (int)roiAgl.at<float>(n, m) / (360 / nAngle)] += roiMag.at<float>(n, m);
				}
			}
		}
	}
	return 0;
}

float O_Distance(float * a, float * b, int n)
{
	float distance = 0;
	for (int i = 0; i < n; i++) {
		distance += (a[i] - b[i])*(a[i] - b[i]);
	}
	distance = sqrt(distance);
	return distance;
}