#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
	Mat srcMat = imread("0.jpg", 0);		
	Mat binaryMat, erodeMat, dilateMat, openingMat, closingMat;
	threshold(srcMat, binaryMat, 0, 255, THRESH_OTSU);		//��ֵͼ
	Mat element = getStructuringElement(MORPH_RECT, Size(3, 3));		
	erode(binaryMat, erodeMat, element);		//��ʴ
	dilate(binaryMat, dilateMat, element);	//����
	morphologyEx(binaryMat, openingMat, MORPH_OPEN, element);	//������
	morphologyEx(binaryMat, closingMat, MORPH_CLOSE, element);	//������

	imshow("frame", srcMat);
	imshow("binaryMat", binaryMat);
	imshow("erode", erodeMat);
	imshow("dilate", dilateMat);
	imshow("opening", openingMat);
	imshow("closing", closingMat);
	//���������ڴ�����Ļ�� ����ImageWatch�鿴

	waitKey(0);
	return 0;
}