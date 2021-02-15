#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	int cnt = 0;
	Mat frame;
	Mat templateMat;
	Mat resultMat;

	VideoCapture cap;    
	cap.open(0);

	while (1) {
		cap >> frame;
		if (!cap.isOpened()) 
		{ 
			cout << "Open failed! Please check your camera !" << endl; 
			return -1; 
		}

		if (cnt == 0)
		{
			Rect2d r = selectROI(frame);
			frame(r).copyTo(templateMat);
			destroyAllWindows();
		}
		else {
			resultMat.create(frame.rows - templateMat.rows, frame.cols - templateMat.cols, CV_32FC1);
			matchTemplate(frame, templateMat, resultMat, TM_CCORR_NORMED);
			normalize(resultMat, resultMat, 0, 1, NORM_MINMAX, -1, Mat());

			double minVal, maxVal;
			Point min, max;
			minMaxLoc(resultMat, &minVal, &maxVal, &min, &max, Mat());
			rectangle(frame, Rect(max.x, max.y, templateMat.cols, templateMat.rows), Scalar(255, 0, 0));

			imshow("resultMat", resultMat);
			imshow("templateMat", templateMat);
			imshow("frame", frame);
		}

		if (waitKey(30) == 27) {
			destroyAllWindows();
			return 0;
		}
		cnt++;
	};

	return 0;
}