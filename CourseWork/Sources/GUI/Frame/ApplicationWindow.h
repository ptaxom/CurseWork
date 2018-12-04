#pragma once
#include <string>
#include <opencv2/highgui.hpp>
#include <Windows.h>
#include "../StatusBar/StatusBar.h"

class ApplicationWindow
{
public:
	ApplicationWindow(std::string title);

	~ApplicationWindow();


	void drawMat(const cv::Mat &frame);

	void updateStatusBar(std::string text);

	std::string getTitle() const;

private:


	HWND getWindow();




	std::string title_;

	//WinAPI stuff
	HWND window_;
	HINSTANCE hInstance_;

	//WinAPI Wrap stuff
	StatusBar statusBar_;
};

