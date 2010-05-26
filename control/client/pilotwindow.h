#ifndef PILOTWINDOW_H
#define PILOTWINDOW_H

#include <QMainWindow>
#include <QToolBar>
#include <QAction>
#include <QTableView>

class QWebView;

class ConnectionManager;
class SensorPanel;
class MotorPanel;
class ArmPanel;

class PilotWindow
	: public QMainWindow
{
	Q_OBJECT

	public:
		PilotWindow(QWidget *parent = 0);

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
	
		MotorPanel *m_motorPanel;
		QWebView *cam1View;
		QWebView *cam2View;

		ConnectionManager *m_connManager;

};

#endif

