#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;

int main()
{
	//ֱ��ͼ����
	Mat srcMat = imread("0.jpg", 0);		//ͼ��ת��Ϊ�Ҷ�ͼ������ά����ת��Ϊһά���飬�Ҷȹ�256��
	int size = 256;
	float histgram[256] = { 0 };
	int height = srcMat.rows;
	int width = srcMat.cols;
	int i, j;
	int total = height * width;
	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			histgram[srcMat.at<uchar>(i, j)]++;
		}
	}


	for (i = 0; i < size; i++)
	{
		histgram[i] /= total;
		cout << "����ֱ��ͼ-�Ҷ�ֵΪ" << i << "�ĸ��ʣ�" << histgram[i] << endl;
	}
	waitKey(0);

	//ֱ��ͼ����
	Mat picture = imread("ֱ��ͼ�װ�.png");
	Point pt1, pt2, pt3, pt;
	Rect rect;
	pt1.x = 0;
	pt1.y = 0;
	pt2.x = 0;
	pt2.y = 800;
	pt3.x = 512;
	pt3.y = 0;
	line(picture, pt1, pt2, CV_RGB(0, 0, 0), 1, 8, 0);
	line(picture, pt1, pt3, CV_RGB(0, 0, 0), 1, 8, 0);
	for (i = 0; i < size; i++)
	{
		rect.x = pt1.x + 2 * i;
		rect.y = pt1.y;
		rect.width = 2;
		rect.height = histgram[i] * 15000;
		rectangle(picture, rect, CV_RGB(0, 0, 255), 1, 8, 0);
	}
	imshow("ֱ��ͼ", picture);
	waitKey(0);
}