#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;
int main()
{
	Mat srcM = imread("21.jpg");
	Mat src, dst1, dst2;
	//�Ҷ�ͼ
	cvtColor(srcM, src, CV_RGB2GRAY);
	//��������Ӧ��ֵ���㷨
	adaptiveThreshold(src, dst1, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 15, 10);
	threshold(src, dst2, 100, 255, THRESH_BINARY);
	//imshow("Binarization by adaptiveThreshold", dst1);
	//imshow("Binarization by threshold", dst2);
	imwrite("21��.jpg", dst2);
	waitKey(0);
}