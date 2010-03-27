#include "mainwindow.h"
#include "createjoystickdialog.h"
#include "createservodialog.h"
#include "qjoystick.h"
#include "joysticksmodel.h"
#include "connectionmanager.h"
#include "servowidget.h"
#include "rovconnection.h"

#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, m_connManager(new ConnectionManager)
{
	m_joysticksModel = new JoysticksModel(this);
	m_joysticksTable = new QTableView(this);
	m_joysticksTable->setModel(m_joysticksModel);
	setCentralWidget(m_joysticksTable);
	setupActions();
	setupToolbars();
}

void MainWindow::addJoystick()
{
	CreateJoystickDialog *d = new CreateJoystickDialog(this);
	if(d->exec())
	{
		QJoystick *j = new QJoystick(d->path(), this);
		m_joysticksModel->addJoystick(*j);
	}
}

void MainWindow::addServoMonitor()
{
	CreateServoDialog *d = new CreateServoDialog(*m_connManager, this);
	if(d->exec())
	{
		ServoWidget *widget = new ServoWidget(d->name(), d->name(), d->connection());
		d->connection().addMonitor(*widget);
		widget->setVisible(true);
	}
}

void MainWindow::setupToolbars()
{
	m_toolBar = new QToolBar(this);
	m_toolBar->addAction(addJoystickAction);
	m_toolBar->addAction(addServoMonitorAction);

	addToolBar(Qt::TopToolBarArea, m_toolBar);
}

void MainWindow::setupActions()
{
	addJoystickAction = new QAction("Add Joystick", this);
	connect(addJoystickAction, SIGNAL(triggered(bool)),
		this, SLOT(addJoystick()));
	addServoMonitorAction = new QAction("Add Servo Monitor", this);
	connect(addServoMonitorAction, SIGNAL(triggered(bool)),
		this, SLOT(addServoMonitor()));
}

#include "mainwindow.moc"

