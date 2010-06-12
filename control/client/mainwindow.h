#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolBar>
#include <QAction>
#include <QTableView>

class JoysticksModel;
class RovConnection;

class MainWindow
	: public QMainWindow
{
	Q_OBJECT

	public:
		MainWindow(QWidget *parent = 0);

		bool waitForConnect();

	private Q_SLOTS:
		void addJoystick();

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

