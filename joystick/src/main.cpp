#include <QApplication>
#include "qjoystick.h"

int main(int argc, char ** argv)
{
	QApplication app( argc, argv );
	QJoystick stick("/dev/input/js0");
	return app.exec();
}
