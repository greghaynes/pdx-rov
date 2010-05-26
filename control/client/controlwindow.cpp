#include "controlwindow.h"
#include "createjoystickdialog.h"
#include "createvarmonitordialog.h"
#include "qjoystick.h"
#include "connectionmanager.h"
#include "servowidget.h"
#include "rovconnection.h"
#include "varmonitorbuilder.h"
#include "armjoystick.h"
#include "propjoystick.h"
#include "sensorpanel.h"
#include "motorpanel.h"
#include "armpanel.h"

#include <QVBoxLayout>
#include <QMenu>
#include <QMenuBar>
#include <QMdiArea>
#include <QMdiSubWindow>
#include <QUrl>
#include <QWebView>

ControlWindow::ControlWindow(QWidget *parent)
	: QMainWindow(parent)
	, m_connManager(ConnectionManager::instance())
{
	QMdiArea *mdiArea = new QMdiArea();
	setCentralWidget(mdiArea);

	m_sensorPanel = new SensorPanel();
	QMdiSubWindow *subwinSensorPanel = mdiArea->addSubWindow(m_sensorPanel);

	cam1View = new QWebView();
	cam1View->load(QUrl("http://google.com"));
	QMdiSubWindow *subwinCam1 = mdiArea->addSubWindow(cam1View);
	subwinCam1->resize(640, 480);

	m_armPanel = new ArmPanel();
	QMdiSubWindow *subwinArmPanel = mdiArea->addSubWindow(m_armPanel);

	setupActions();
	setupMenus();
	setupToolbars();
}

void ControlWindow::addJoystick()
{
	CreateJoystickDialog *d = new CreateJoystickDialog(this);
	if(d->exec())
	{
		RovJoystick *j = 0;
		switch(d->type())
		{
			case RovJoystick::Arm:
				j = new ArmJoystick(d->path(), d->connection(), this);
				break;
			case RovJoystick::Propulsion:
				j = new PropJoystick(d->path(), d->connection(), this);
		}
	}
}

void ControlWindow::addVarMonitor()
{
	CreateVarMonitorDialog *d = new CreateVarMonitorDialog(*m_connManager, this);
	if(d->exec())
	{
		VarMonitorBuilder::instance().createVarMonitor(d->connection(), d->name());
	}
}

void ControlWindow::setupToolbars()
{
	m_toolBar = new QToolBar(this);
	m_toolBar->addAction(addConnectionAction);
	m_toolBar->addAction(addJoystickAction);
	m_toolBar->addAction(addVarMonitorAction);

	addToolBar(Qt::TopToolBarArea, m_toolBar);
}

void ControlWindow::setupMenus()
{
	QMenu *fileMenu = new QMenu("&File", this);
	fileMenu->addAction(addConnectionAction);
	fileMenu->addAction(addJoystickAction);
	fileMenu->addAction(addVarMonitorAction);
	fileMenu->addAction(quitAction);
	
	menuBar()->addMenu(fileMenu);
}

void ControlWindow::setupActions()
{
	quitAction = new QAction("&Quit", this);
	quitAction->setShortcut(QKeySequence::Close);
	connect(quitAction, SIGNAL(triggered(bool)),
		this, SLOT(close()));

	addConnectionAction = new QAction("Add &Connection", this);
	connect(addConnectionAction, SIGNAL(triggered(bool)),
		m_connManager, SLOT(createConnection()));
	addJoystickAction = new QAction("Add &Joystick", this);
	connect(addJoystickAction, SIGNAL(triggered(bool)),
		this, SLOT(addJoystick()));
	addVarMonitorAction = new QAction("Add &Variable Monitor", this);
	connect(addVarMonitorAction, SIGNAL(triggered(bool)),
		this, SLOT(addVarMonitor()));
}

#include "controlwindow.moc"

