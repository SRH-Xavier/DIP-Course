//程序功能：磨皮


#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main()
{
	Mat srcMat = imread("0.jpg");	//无摄像头，采取本地图片代替，图片来源于网络，侵删

	double scale = 1;		//缩放倍数
	double i_minh = 0, i_maxh = 20;		//皮肤HSV数据
	double i_mins = 43, i_maxs = 255;
	double i_minv = 55, i_maxv = 255;

	Mat  hsvMat, detectMat, GaussMat, dstMat;

	Size ResImgSize = Size(srcMat.cols*scale, srcMat.rows*scale);//目标像素提取部分
	Mat rFrame = Mat(ResImgSize, srcMat.type());
	resize(srcMat, rFrame, ResImgSize, INTER_LINEAR);

	cvtColor(rFrame, hsvMat, COLOR_BGR2HSV);		//转换为HSV格式
	rFrame.copyTo(detectMat);
	inRange(hsvMat, Scalar(i_minh, i_mins, i_minv), Scalar(i_maxh, i_maxs, i_maxv), detectMat);

	Size ksize = Size(7, 7);
	double sigmaX = 1;
	double sigmaY = 1;

	GaussianBlur(rFrame, GaussMat, ksize, sigmaX, sigmaY);
	rFrame.copyTo(dstMat);
	GaussMat.copyTo(dstMat, detectMat);   //Mask蒙版 

	imshow("原图", srcMat);
	imshow("磨皮后", dstMat);		//直接显示图片较小，可以使用ImageWatch进行详细对比

	waitKey(0);
	return 0;

}
