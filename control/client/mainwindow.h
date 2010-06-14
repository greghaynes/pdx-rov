#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolBar>
#include <QAction>
#include <QTableView>

class JoysticksModel;
class QJoystick;
class RovConnection;

class MainWindow
	: public QMainWindow
{

	public:
		MainWindow(RovConnection &conn,
			QWidget *parent = 0);

		bool waitForConnect();

	public:
		void addJoystick(QJoystick &joystick);

	private:
		void setupToolbars();
		void setupActions();
		void setupMenus();

		QToolBar *m_toolBar;
		QAction *addJoystickAction;
		QAction *addVarMonitorAction;
		QAction *addConnectionAction;
		QAction *quitAction;
		QTableView *m_joysticksTable;
		JoysticksModel *m_joysticksModel;
		RovConnection *m_connection;

};

#endif

