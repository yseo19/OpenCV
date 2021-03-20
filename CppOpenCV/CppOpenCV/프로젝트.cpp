#include "opencv2/opencv.hpp"
#include <iostream>
#include <vector>

using namespace std;
using namespace cv;

void affine_transform() {
	VideoCapture cap("ез╥п.mp4");
	int i;
	if (!cap.isOpened()) {
		cerr << "video load failed" << endl;
		return;
	}


	double fps = cap.get(CAP_PROP_FPS);
	cout << "FPS : " << fps << endl;

	int delay = cvRound(1000 / fps);
	int pos = 0;

	Mat frame;
	vector<Mat> frames;

	while (true) {
		cap >> frame;
		frames.push_back(frame);
		if (frame.empty())
			break;

		imshow("frames", frames[0]);

		int keycode = waitKeyEx(1);

		if (keycode == 0x270000) {
			for (i = 0; i < fps * 5; i++) {
				cap >> frame;
				frames.push_back(frame);
			}
			pos += fps * 5;
				//cap.grab();
		}
		if (keycode == 0x250000) {
			pos -= fps * 5;
			if (pos < 0) pos = 0;
		}
		if (keycode == 0x260000) {
			waitKey();
		}
		if (keycode == 27)
			break;
	}

	destroyAllWindows();
}

int main(void) {
	affine_transform();
	return 0;
}