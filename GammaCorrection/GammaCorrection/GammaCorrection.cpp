//gammaÐ£Õý


#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void gamma_correction(Mat& src, Mat& dst, float K) {
	uchar Lut[256];
	src.copyTo(dst);

	for (int i = 0; i < 256; i++) {
		float f = i / 255.0;
		f = pow(f, K);
		Lut[i] = saturate_cast<uchar>(f*255.0);
	}

	MatIterator_<cv::Vec3b> flag = dst.begin<cv::Vec3b>();
	MatIterator_<cv::Vec3b> end = dst.end<cv::Vec3b>();

	for (; flag != end; flag++) {
		(*flag)[0] = Lut[(*flag)[0]];
		(*flag)[1] = Lut[(*flag)[1]];
		(*flag)[2] = Lut[(*flag)[2]];
	}

}

int main() {

	Mat srcMat = imread("0.jpg");
	Mat dstMat;
	float gamma = 0.4;

	gamma_correction(srcMat, dstMat, gamma);

	imshow("srcMat", srcMat);
	imshow("dstMat", dstMat);

	waitKey(0);
	return 0;

}

