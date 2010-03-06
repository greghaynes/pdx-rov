#ifndef JOYSTICK_MANAGER_WINDOW_H
#define JOYSTICK_MANAGER_WINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QList>

class QJoystickWidget;

class JoystickManagerWindow
	: public QMainWindow
{
	Q_OBJECT

	public:
		JoystickManagerWindow(QWidget *parent = 0);

	private Q_SLOTS:
		void addJoystick();

	private:
		void createActions();
		void createMenus();
		void connectSignals();

		QAction *addJoystickAction;
		QList<QJoystickWidget*> *joystickWidgets;

};

#endif

