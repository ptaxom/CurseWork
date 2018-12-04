#include <opencv2/highgui.hpp>
#include "Frame/ApplicationWindow.h"

int main()
{

	cv::VideoCapture cap;
	cv::Mat frame;
	cap.open(0);
	ApplicationWindow window("WebCam");

	while (1)
	{
		cap.read(frame);
		window.drawMat(frame);
		if (cv::waitKey(1) >= 0)
			break;
	}
	return 0;
}