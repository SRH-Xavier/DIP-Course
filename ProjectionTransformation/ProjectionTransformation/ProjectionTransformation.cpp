//�����ܣ�ͶӰ�任


#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	Mat dstMat;
	Mat srcMat = imread("0.jpg");
	//�任ǰ���ĵ�����
	const Point2f src_pt[] = {
									Point2f(150,150),
									Point2f(150,300),
									Point2f(350,300),
									Point2f(350,150) };
	//�任����ĵ�����
	const Point2f dst_pt[] = {
									Point2f(200,150),
									Point2f(200,300),
									Point2f(340,270),
									Point2f(340,180) };

	//���ͶӰ�任����
	Mat perspect_matrix = getPerspectiveTransform(src_pt, dst_pt);
	//�任
	warpPerspective(srcMat, dstMat, perspect_matrix, srcMat.size());

	imshow("srcMat", srcMat);
	imshow("dstMat", dstMat);
	waitKey(0);
}


