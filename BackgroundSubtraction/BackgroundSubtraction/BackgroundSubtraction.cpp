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
			// ��һ֡����ñ���ͼ��
			frame.copyTo(backMat);
		}
		else {
			// �ڶ�֡��ʼ�������
			// ����ͼ��͵�ǰͼ�����
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

