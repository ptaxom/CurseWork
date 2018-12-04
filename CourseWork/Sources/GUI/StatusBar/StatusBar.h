#pragma once
#include <Windows.h>
#include <vector>
#include <string>
#include <CommCtrl.h>

class StatusBar
{
public:
	
	StatusBar() {}


	StatusBar(HWND parent, HINSTANCE hInst);

	void updateField(const std::string &field);


	HWND getBar() const
	{
		return statusBar_;
	}

private:
	HWND parent_;
	HWND statusBar_;

};

