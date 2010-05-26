#ifndef CONTROLWINDOW_H
#define CONTROLWINDOW_H

#include <QMainWindow>
#include <QToolBar>
#include <QAction>
#include <QTableView>

class QWebView;

class ConnectionManager;
class SensorPanel;
class MotorPanel;
class ArmPanel;

class ControlWindow
	: public QMainWindow
{
	Q_OBJECT

	public:
		ControlWindow(QWidget *parent = 0);

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
	
		ArmPanel *m_armPanel;
		SensorPanel *m_sensorPanel;
		QWebView *cam1View;

		ConnectionManager *m_connManager;

};

#endif

