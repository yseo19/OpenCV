#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

void constrast1() {
	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);

	if (src.empty()) {
		cerr << "Image load failed" << endl;
		return;
	}

	float s = 2.f;
	Mat dst = s * src;

	imshow("src", src);
	imshow("dst", dst);

	waitKey();
	destroyAllWindows();
}

int main(void) {
	constrast1();
	return 0;
}