#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int GaussianModelBackground(vector<Mat> srcMats, Mat& meanMat, Mat& varMat)
{
	int rows = srcMats[0].rows;
	int cols = srcMats[0].cols;

	for (int height = 0; height < rows; height++)
	{
		for (int width = 0; width < cols; width++)
		{
			int sum = 0;	
			float var = 0;

			for (int i = 0; i < srcMats.size(); i++) {
				sum += srcMats[i].at<uchar>(height, width);
			}
			meanMat.at<uchar>(height, width) = sum / srcMats.size();

			for (int i = 0; i < srcMats.size(); i++) {
				var += pow((srcMats[i].at<uchar>(height, width) - meanMat.at<uchar>(height, width)), 2);
			}
			varMat.at<float>(height, width) = var / srcMats.size();
		}
	}
	return 0;
}

int GaussianThreshold(Mat srcMat, Mat meanMat,Mat varMat, float nSigma, Mat& dstMat)
{
	int srcValue;
	int meanValue;
	int rows = srcMat.rows;
	int cols = srcMat.cols;

	for (int height = 0; height < rows; height++)
	{
		for (int width = 0; width < cols; width++)
		{
			srcValue = srcMat.at<uchar>(height, width);
			meanValue = meanMat.at<uchar>(height, width);
			int dif = abs(srcValue - meanValue);
			int th = nSigma * varMat.at<float>(height, width);

			if (dif > th) {
				dstMat.at<uchar>(height, width) = 255;
			}
			else {
				dstMat.at<uchar>(height, width) = 0;
			}
		}
	}
	return 0;
}

int main()
{
	VideoCapture cap;
	cap.open(0);
	if (!cap.isOpened()) { cout << "Open failed! Please check your camera or files!" << endl; return -1; }

	int cnt = 0;
	Mat frame;
	Mat meanMat;
	Mat varMat;
	Mat dstMat;
	vector<Mat> srcMats;
	int nBackground = 100;		// 预处理背景帧
	float nSigma = 2;		// Sigma的n倍阈值

	while (true)
	{
		cap >> frame;
		cvtColor(frame, frame, COLOR_BGR2GRAY);

		if (cnt < nBackground) {
			srcMats.push_back(frame);
		}
		else if (cnt == nBackground) {
			meanMat.create(frame.size(), CV_8UC1);
			varMat.create(frame.size(), CV_32FC1);
			GaussianModelBackground(srcMats, meanMat, varMat);
		}
		else {
			dstMat.create(frame.size(), CV_8UC1);
			GaussianThreshold(frame, meanMat, varMat, nSigma, dstMat);
			imshow("dstMat", dstMat);
			imshow("frame", frame);
			waitKey(30);
		}
		cnt++;
	}
}