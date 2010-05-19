#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolBar>
#include <QAction>
#include <QTableView>

class ConnectionManager;
class MotorPanel;
class ArmPanel;

class MainWindow
	: public QMainWindow
{
	Q_OBJECT

	public:
		MainWindow(QWidget *parent = 0);

	private Q_SLOTS:
		void addJoystick();
		void addVarMonitor();

	private:
		void setupToolbars();
		void setupActions();
		void setupMenus();

		QToolBar *m_toolBar;

		QAction *addJoystickAction;
		QAction *addVarMonitorAction;
		QAction *addConnectionAction;
		QAction *quitAction;
	
		ConnectionManager *m_connManager;
		MotorPanel *m_motorPanel;
		ArmPanel *m_armPanel;

};

#endif

