#include <opencv2/highgui.hpp>
#include "GUI/Frame/ApplicationWindow.h"


HWND getWindow(std::string title_)
{

	HWND hwnd;
	char p[100];
	hwnd = GetDesktopWindow();
	hwnd = GetWindow(hwnd, GW_CHILD);
	while (hwnd != 0)
	{
		hwnd = GetWindow(hwnd, GW_HWNDNEXT);
		GetWindowText(hwnd, p, 100);
		if (strlen(p) > 0)
		{
			std::string hwndName = std::string(p);
			if (hwndName == title_)
				return hwnd;
		}
	}
	return NULL;
}

#include <iostream>
#include <time.h>
#include <string>

int mai2n()
{

	cv::VideoCapture cap;
	cv::Mat frame;
	cap.open(0);
	std::string title = "SS";


	cv::namedWindow(title);

	HWND window = getWindow(title);
	HINSTANCE hInst = (HINSTANCE)GetModuleHandle(NULL);

	HWND statusBar_ = CreateWindowEx(
		0L,
		STATUSCLASSNAME,
		"",
		WS_CHILD | WS_BORDER |
		WS_VISIBLE | SBARS_SIZEGRIP,
		0, 0, 0, 0,
		window,
		(HMENU)801,
		hInst,
		NULL);


	int ptWidth[3] = { 100, 200, -1 };
	SendMessage(statusBar_, SB_SETPARTS, 3, (LPARAM)ptWidth);

	SendMessage(statusBar_, SB_SETTEXT, 0, (LPARAM)"");
	SendMessage(statusBar_, SB_SETTEXT, 1 | SBT_NOBORDERS,
		(LPARAM)"");


	double times = 0.0, sum = 0.0;

	while (1)
	{
		time_t start, end;
		time(&start);
		cap.read(frame);
		cv::imshow(title, frame);
		if (cv::waitKey(1) >= 0 || cvGetWindowProperty(title.c_str(), 0) < 0)
			break;
		time(&end);
		times += 1.0; sum += (double)(end - start);
		double fps = 1.0 / (sum / times);
		SendMessage(statusBar_, SB_SETTEXT, 0, (LPARAM)(std::string("FPS  ") + std::to_string(fps)).c_str());
	}
	return 0;
}