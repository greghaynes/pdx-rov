#include <QApplication>
#include "mainwindow.h"

int main(int argc, char **argv)
{
	QApplication app(argc, argv);
	
	MainWindow *mainWindow = new MainWindow();
	mainWindow->setVisible(true);
	
	return app.exec();
}

