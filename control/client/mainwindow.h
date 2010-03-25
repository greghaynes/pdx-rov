#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolBar>
#include <QAction>
#include <QTableView>

class JoysticksModel;

class MainWindow
	: public QMainWindow
{
	Q_OBJECT

	public:
		MainWindow(QWidget *parent = 0);

	private Q_SLOTS:
		void addJoystick();

	private:
		void setupToolbars();
		void setupActions();

		QToolBar *m_toolBar;
		QAction *addJoystickAction;
		QTableView *m_joysticksTable;
		JoysticksModel *m_joysticksModel;

};

#endif

