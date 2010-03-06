#include <QApplication>
#include "joystickmanagerwindow.h"

int main(int argc, char ** argv)
{
	QApplication app( argc, argv );
	JoystickManagerWindow window;
	window.setVisible(true);
	return app.exec();
}
