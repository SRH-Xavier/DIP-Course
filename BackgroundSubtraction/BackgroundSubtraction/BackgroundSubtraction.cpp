#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main() {
	int cnt = 0;
	Mat frame;
	Mat backMat;
	Mat subMat;
	Mat binarySubMat;

	VideoCapture cap;
	cap.open(0);
	if (!cap.isOpened()) { cout << "Open failed! Please check your camera or files!" << endl; return -1; }

	while (1) {
		cap >> frame;
		cvtColor(frame, frame, COLOR_BGR2GRAY);

		if (cnt == 0) {
			// 第一帧，获得背景图像
			frame.copyTo(backMat);
		}
		else {
			// 第二帧开始背景差分
			// 背景图像和当前图像相减
			absdiff(frame, backMat, subMat);
			threshold(subMat, binarySubMat, 50, 255, CV_THRESH_BINARY);

			imshow("binarySubMat", binarySubMat);
			imshow("subMat", subMat);
			waitKey(30);
		}
		cnt++;
	}

	return 0;
}

