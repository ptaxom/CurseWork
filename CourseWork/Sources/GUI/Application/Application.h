#pragma once
#include <string>
#include "../Frame/ApplicationWindow.h"
#include "../../Controller/Settings/ApplicationSettings/ApplicationSettings.h"
#include "../../Controller/KeyboardController/KeyboardController.h"

class Application
{
public:

	Application(std::string title);

	~Application();

private:

	ApplicationWindow mainWindow_;
	ApplicationSettings appSettings_;
	KeyboardController kbContoller_;


};

