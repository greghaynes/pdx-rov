#include <QApplication>
#include "controlwindow.h"

int main(int argc, char **argv)
{
	QApplication app(argc, argv);
	
	ControlWindow *mainWindow = new ControlWindow();
	mainWindow->setVisible(true);
	
	return app.exec();
}

