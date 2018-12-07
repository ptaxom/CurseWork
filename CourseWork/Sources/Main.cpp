#include "GUI/Frame/ApplicationWindow.h"
#include <opencv2/highgui.hpp>
#include <time.h>

int main2()
{
	cv::VideoCapture cap;
	cap.open(0);
	cv::Mat frame;

	ApplicationWindow window("WebCam");

	double times = 0.0, sum = 0.0;

	while (1)
	{
		time_t start, end;
		time(&start);
		cap.read(frame);
		window.drawMat(frame);
		if (cv::waitKey(1) >= 0 || cvGetWindowProperty(window.getTitle().c_str(), 0) < 0)
			break;
		time(&end);
		times += 1.0; sum += (double)(end - start);
		double fps = 1.0 / (sum / times);
		window.updateStatusBar("FPS: " + std::to_string(fps));
	}


	return 0;
}