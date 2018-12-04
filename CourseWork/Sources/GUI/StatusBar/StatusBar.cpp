#include "StatusBar.h"

StatusBar::StatusBar(HWND parent, HINSTANCE hInst) : parent_(parent)
{
	statusBar_ = CreateWindowEx(
		0L,                     
		STATUSCLASSNAME,       
		"",                     
		WS_CHILD | WS_BORDER | 
		WS_VISIBLE | SBARS_SIZEGRIP,
		0, 0, 0, 0,            
		parent_,                 
		(HMENU)801,   
		hInst,
		NULL);


	int ptWidth[3] = { 100, 200, -1 };
	SendMessage(statusBar_, SB_SETPARTS, 3, (LPARAM)ptWidth);

	SendMessage(statusBar_, SB_SETTEXT, 0, (LPARAM)"");
	SendMessage(statusBar_, SB_SETTEXT, 1 | SBT_NOBORDERS,
		(LPARAM)"");
}

void StatusBar::updateField(const std::string & field)
{
	SendMessage(statusBar_, SB_SETTEXT, 0, (LPARAM)field.c_str());
}
