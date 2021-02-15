//�����ܣ�����任


#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	Mat dstMat;
	Mat srcMat = imread("0.jpg");
	//�任ǰ����������
	const Point2f src_pt[] = {
									Point2f(200,200),
									Point2f(250,200),
									Point2f(200,100) };
	//�任�����������
	const Point2f dst_pt[] = {
									Point2f(300,100),
									Point2f(300,50),
									Point2f(200,100) };

	//����������
	const Mat affine_matrix = getAffineTransform(src_pt, dst_pt);

	warpAffine(srcMat, dstMat, affine_matrix, srcMat.size());

	imshow("srcMat", srcMat);
	imshow("dstMat", dstMat);
	waitKey(0);
}
