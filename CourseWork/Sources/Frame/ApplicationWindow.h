#pragma once
#include <string>
#include <opencv2/highgui.hpp>
#include <Windows.h>

class ApplicationWindow
{
public:
	ApplicationWindow(std::string title);

	~ApplicationWindow();


	void drawMat(const cv::Mat &frame);

private:


	HWND getWindow();




	std::string title_;

	//WinAPI stuff
	HWND window_;
	HINSTANCE hInstance_;
};

