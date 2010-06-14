#include <QApplication>
#include <QFileInfo>

#include <iostream>

#include "mainwindow.h"

int main(int argc, char **argv)
{
	QApplication app(argc, argv);

	QFileInfo propstick_info("/dev/input/js0");
	QFileInfo armstick_info("/dev/input/js1");

	if(!propstick_info.exists())
	{
		std::cout << "No propulsion joystick found.\n";
		return 1;
	}

	if(!armstick_info.exists())
	{
		std::cout << "No arm joystick found.\n";
		return 1;
	}
	
	MainWindow *mainWindow = new MainWindow();
	mainWindow->setVisible(true);
	if(mainWindow->waitForConnect())
		return app.exec();
}

