#include "joystickmanagerwindow.h"

#include <QMenu>
#include <QMenuBar>
#include <QMessageBox>

JoystickManagerWindow::JoystickManagerWindow(QWidget *parent)
	: QMainWindow(parent)
{
	createActions();
	createMenus();
	connectSignals();
}

void JoystickManagerWindow::addJoystick()
{
	QMessageBox::information(this, "Add joystick", "Add Joystick");
}

void JoystickManagerWindow::createActions()
{
	addJoystickAction = new QAction("Add Joystick", this);
}

void JoystickManagerWindow::createMenus()
{
	QMenu *fileMenu = new QMenu("File");
	fileMenu->addAction(addJoystickAction);

	menuBar()->addMenu(fileMenu);
}

void JoystickManagerWindow::connectSignals()
{
	connect(addJoystickAction, SIGNAL(triggered(bool)),
		this, SLOT(addJoystick()));
}

