#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

void contrast2() {
	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);

	if (src.empty()) {
		cerr << "Image load failed" << endl;
		return;
	}

	float alpha = 1.f;
	Mat dst = src + (src - 128) * alpha;

	imshow("src", src);
	imshow("dst", dst);

	waitKey();
	destroyAllWindows();

}
int main(void) {
	contrast2();
	return 0;
	
}