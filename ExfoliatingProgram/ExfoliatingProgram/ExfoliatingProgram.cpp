//�����ܣ�ĥƤ


#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main()
{
	Mat srcMat = imread("0.jpg");	//������ͷ����ȡ����ͼƬ���棬ͼƬ��Դ�����磬��ɾ

	double scale = 1;		//���ű���
	double i_minh = 0, i_maxh = 20;		//Ƥ��HSV����
	double i_mins = 43, i_maxs = 255;
	double i_minv = 55, i_maxv = 255;

	Mat  hsvMat, detectMat, GaussMat, dstMat;

	Size ResImgSize = Size(srcMat.cols*scale, srcMat.rows*scale);//Ŀ��������ȡ����
	Mat rFrame = Mat(ResImgSize, srcMat.type());
	resize(srcMat, rFrame, ResImgSize, INTER_LINEAR);

	cvtColor(rFrame, hsvMat, COLOR_BGR2HSV);		//ת��ΪHSV��ʽ
	rFrame.copyTo(detectMat);
	inRange(hsvMat, Scalar(i_minh, i_mins, i_minv), Scalar(i_maxh, i_maxs, i_maxv), detectMat);

	Size ksize = Size(7, 7);
	double sigmaX = 1;
	double sigmaY = 1;

	GaussianBlur(rFrame, GaussMat, ksize, sigmaX, sigmaY);
	rFrame.copyTo(dstMat);
	GaussMat.copyTo(dstMat, detectMat);   //Mask�ɰ� 

	imshow("ԭͼ", srcMat);
	imshow("ĥƤ��", dstMat);		//ֱ����ʾͼƬ��С������ʹ��ImageWatch������ϸ�Ա�

	waitKey(0);
	return 0;

}
