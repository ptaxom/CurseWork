#include "ApplicationWindow.h"


ApplicationWindow::ApplicationWindow(std::string title) : title_(title)
{
	cv::namedWindow(title_);
	window_ = getWindow();
	hInstance_ = (HINSTANCE)GetModuleHandle(NULL);
	statusBar_ = StatusBar(window_, hInstance_);
}

ApplicationWindow::~ApplicationWindow()
{
	cv::destroyWindow(title_);
}

void ApplicationWindow::drawMat(const cv::Mat & frame)
{
	cv::imshow(title_, frame);
}

void ApplicationWindow::updateStatusBar(std::string text)
{
	statusBar_.updateField(text);
}

std::string ApplicationWindow::getTitle() const
{
	return title_;
}

HWND ApplicationWindow::getWindow()
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
