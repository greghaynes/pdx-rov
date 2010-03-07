#include <QApplication>
#include "rovjoystick.h"
#include "rovconnection.h"

int main(int argc, char **argv)
{
	QApplication app(argc, argv);
	
	RovJoystick rovStick("/dev/input/js1");
	rovStick.connection().connectToHost("localhost", 8081);
	
	return app.exec();
}

