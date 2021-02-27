#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

void color_split() {
	Mat src = imread("m&m.jpg");

	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}

	vector<Mat> bgr_planes;
	split(src, bgr_planes);

	imshow("src", src);
	imshow("B_plane", bgr_planes[0]);
	imshow("G_plane", bgr_planes[1]);
	imshow("R_plane", bgr_planes[2]);

	waitKey();
	destroyAllWindows();
}

int main(void) {
	color_split();
	return 0;
}