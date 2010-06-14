#include "mainwindow.h"
#include "createjoystickdialog.h"
#include "createvarmonitordialog.h"
#include "joysticksmodel.h"
#include "servowidget.h"
#include "rovconnection.h"
#include "varmonitorbuilder.h"
#include "armjoystick.h"
#include "propjoystick.h"
#include "connectingdialog.h"

#include <QVBoxLayout>
#include <QMenu>
#include <QMenuBar>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, m_connection(new RovConnection("rov", this))
{
	m_joysticksModel = new JoysticksModel(this);
	m_joysticksTable = new QTableView(this);
	m_joysticksTable->setModel(m_joysticksModel);
	setCentralWidget(m_joysticksTable);
	setupActions();
	setupMenus();
	setupToolbars();
}

void MainWindow::addJoystick()
{
	CreateJoystickDialog *d = new CreateJoystickDialog(this);
	if(d->exec())
	{
		RovJoystick *j = 0;
		switch(d->type())
		{
			case RovJoystick::Arm:
				j = new ArmJoystick(d->path(), *m_connection, this);
				break;
			case RovJoystick::Propulsion:
				j = new PropJoystick(d->path(), *m_connection, this);
		}
		
		if(j)
		{
			m_joysticksModel->addJoystick(*j);
		}
	}
}

bool MainWindow::waitForConnect()
{
	ConnectingDialog *cd = new ConnectingDialog(this);
	bool val = cd->waitForConnectionOn(*m_connection);
	if(val)
	{
		RovJoystick *j = new ArmJoystick("/dev/input/js0", *m_connection, this);
		m_joysticksModel->addJoystick(*j);
		j = new ArmJoystick("/dev/input/js1", *m_connection, this);
		m_joysticksModel->addJoystick(*j);
	}
	return val;
}

void MainWindow::setupToolbars()
{
	m_toolBar = new QToolBar(this);
	m_toolBar->addAction(addConnectionAction);
	m_toolBar->addAction(addJoystickAction);
	m_toolBar->addAction(addVarMonitorAction);

	addToolBar(Qt::TopToolBarArea, m_toolBar);
}

void MainWindow::setupMenus()
{
	QMenu *fileMenu = new QMenu("&File", this);
	fileMenu->addAction(addConnectionAction);
	fileMenu->addAction(addJoystickAction);
	fileMenu->addAction(addVarMonitorAction);
	fileMenu->addAction(quitAction);
	
	menuBar()->addMenu(fileMenu);
}

void MainWindow::setupActions()
{
	quitAction = new QAction("&Quit", this);
	quitAction->setShortcut(QKeySequence::Close);
	connect(quitAction, SIGNAL(triggered(bool)),
		this, SLOT(close()));

	addConnectionAction = new QAction("Add &Connection", this);
	addJoystickAction = new QAction("Add &Joystick", this);
	connect(addJoystickAction, SIGNAL(triggered(bool)),
		this, SLOT(addJoystick()));
	addVarMonitorAction = new QAction("Add &Variable Monitor", this);
	connect(addVarMonitorAction, SIGNAL(triggered(bool)),
		this, SLOT(addVarMonitor()));
}

#include "mainwindow.moc"

