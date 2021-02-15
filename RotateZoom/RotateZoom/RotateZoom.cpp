//�����ܣ���ת������


#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	Mat dstMat;
	Mat srcMat = imread("0.jpg");

	//˳ʱ����ת30�㣬���ų߶�Ϊ2
	float angle = -30.0, scale = 0.5;
	//��ת����Ϊͼ������
	Point2f center(srcMat.cols*0.5, srcMat.rows*0.5);
	//��ñ任����
	const Mat affine_matrix = getRotationMatrix2D(center, angle, scale);
	warpAffine(srcMat, dstMat, affine_matrix, srcMat.size());

	imshow("srcMat", srcMat);
	imshow("dstMat", dstMat);
	waitKey(0);
}


