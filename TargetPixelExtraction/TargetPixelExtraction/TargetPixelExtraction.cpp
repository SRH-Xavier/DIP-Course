#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
	//无摄像头 调取本地图片替代 有摄像头的电脑可以采用注释掉的部分
	//VideoCapture cap;
	//cap.open(0);		
	Mat frame;				
	frame = imread("0.jpg");		
	double scale = 0.25;
	//肤色
	double i_minh = 0;
	double i_maxh = 20;
	double i_mins = 43;
	double i_maxs = 255;
	double i_minv = 55;
	double i_maxv = 255;

	//while (1)
	//{
		Mat hsvMat;
		Mat detectMat;
		//cap >> frame;
		Size ResImgSize = Size(frame.cols*scale, frame.rows*scale);
		Mat rFrame = Mat(ResImgSize, frame.type());
		resize( frame,rFrame, ResImgSize, INTER_LINEAR);
		cvtColor(rFrame, hsvMat, COLOR_BGR2HSV);
		rFrame.copyTo(detectMat);
		cv::inRange(hsvMat, Scalar(i_minh, i_mins, i_minv), Scalar(i_maxh, i_maxs, i_maxv), detectMat);
		
	//}
	imshow("while:in the range", detectMat);
	imshow("frame", rFrame);
	waitKey(0);





}