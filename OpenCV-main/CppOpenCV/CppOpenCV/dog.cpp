#include "opencv2\opencv.hpp"

using namespace cv;

void Matop2() {
	Mat img1 = imread("dog.bmp");
	Mat img2 = img1;
	Mat img3;
	img3 = img1;

	Mat img4 = img1.clone();
	Mat img5;
	img1.copyTo(img5);

	img1.setTo(Scalar(0, 225, 225));

	imshow("img1", img1);
	imshow("img2", img2);
	imshow("img3", img3);
	imshow("img4", img4);
	imshow("img5", img5);

	waitKey();
	destroyAllWindows();
}

int main(void) {
	Matop2();

	return 0;
}