//�����ܣ�X��Y�����Ե��ȡ


#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;
int main()
{
	Mat dx, dy, absx, absy;
	Mat srcMat = imread("0.jpg");		//������ͷ�����ñ���ͼƬ����

	Sobel(srcMat, dx, CV_16S, 1, 0, 3);
	convertScaleAbs(dx, absx);	//ͼ����ǿ
	Sobel(srcMat, dy, CV_16S, 0, 1, 3);
	convertScaleAbs(dy, absy);

	imshow("ԭͼ", srcMat);
	imshow("X�����ϵı�Ե��ȡ", absx);
	imshow("Y�����ϵı�Ե��ȡ", absy);

	waitKey(0);
	return 0;
}