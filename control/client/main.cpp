#include <QApplication>
#include <QFileInfo>

#include <iostream>

#include "connectingdialog.h"
#include "propjoystick.h"
#include "armjoystick.h"
#include "rovconnection.h"
#include "mainwindow.h"
#include "joysticksmodel.h"

#define PROP_JOYSTICK "/dev/input/js0"
#define ARM_JOYSTICK "/dev/input/js1"

int main(int argc, char **argv)
{
	QApplication app(argc, argv);

	QFileInfo propstick_info(PROP_JOYSTICK);
	QFileInfo armstick_info(ARM_JOYSTICK);

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

	RovConnection connection;
	ConnectingDialog cd;
	if(cd.waitForConnectionOn(connection))
	{
		MainWindow *mainWindow = new MainWindow(connection);

		PropJoystick pj(PROP_JOYSTICK, connection);
		ArmJoystick aj(ARM_JOYSTICK, connection);

		mainWindow->joysticksModel().addJoystick(pj);
		mainWindow->joysticksModel().addJoystick(aj);
		mainWindow->setVisible(true);

		return app.exec();
	}
	else
	{
		std::cout << "Couldnt connect to ROV.\n";
		return 1;
	}
}

