#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
	Mat src_color = imread("1.jpg");
	vector<Mat> channels;
	split(src_color, channels);
	imshow("blue", channels.at(0));
	imshow("green", channels.at(1));
	imshow("red", channels.at(2));
	imshow("original", src_color);
	waitKey(0);
}