//�����ܣ���ֵ�˲�����ֵ�˲�����˹�˲�


#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;
int main()
{
	//����������ͷ���ñ���ͼƬ����
	Mat medianMat, meanMat, gaussianMat;
	Mat srcMat = imread("0.jpg");

	//��ֵ�˲�
	int mediansize = 7;
	medianBlur(srcMat, medianMat, mediansize);
	//��ֵ�˲�
	Size blursize = Size(7, 7);
	blur(srcMat, meanMat, blursize);
	//��˹�˲�
	double sigmaX = 1;
	double sigmaY = 1;
	Size Gaussiansize = Size(7, 7);
	GaussianBlur(srcMat, gaussianMat, Gaussiansize, sigmaX, sigmaY);

	imshow("ԭͼ ", srcMat);
	imshow("��ֵ�˲�", medianMat);
	imshow("��ֵ�˲�", meanMat);
	imshow("��˹�˲�", gaussianMat);

	waitKey(0);
	return 0;
}