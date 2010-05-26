#include <QApplication>
#include "pilotwindow.h"

int main(int argc, char **argv)
{
	QApplication app(argc, argv);
	
	PilotWindow *mainWindow = new PilotWindow();
	mainWindow->setVisible(true);
	
	return app.exec();
}

