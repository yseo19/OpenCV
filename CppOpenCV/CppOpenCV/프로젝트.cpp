#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

#include "opencv2/opencv.hpp"
#include <iostream>

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

	Mat frame;

	while (true) {
		cap >> frame;
		if (frame.empty())
			break;


		/*Point2f srcPts[3], dstPts[3];
		srcPts[0] = Point2f(0, 0);
		srcPts[1] = Point2f(frame.cols - 1, 0);
		srcPts[2] = Point2f(frame.cols - 1, frame.rows - 1);
		dstPts[0] = Point2f(50, 50);
		dstPts[1] = Point2f(frame.cols - 100, 100);
		dstPts[2] = Point2f(frame.cols - 50, frame.rows - 50);

		Mat M = getAffineTransform(srcPts, dstPts);

		Mat dst;
		warpAffine(frame, dst, M, Size());
		*/
		imshow("frame", frame);
		//imshow("dst", dst);

		int keycode = waitKeyEx(1);

		if (keycode == 0x270000) {
			for (i = 0; i < fps * 5; i++)
				cap.grab();
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