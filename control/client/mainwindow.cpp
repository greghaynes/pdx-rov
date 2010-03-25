#include "mainwindow.h"
#include "createjoystickdialog.h"
#include "qjoystick.h"
#include "joysticksmodel.h"

#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
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

void MainWindow::setupToolbars()
{
	m_toolBar = new QToolBar(this);
	m_toolBar->addAction(addJoystickAction);

	addToolBar(Qt::TopToolBarArea, m_toolBar);
}

void MainWindow::setupActions()
{
	addJoystickAction = new QAction("Add Joystick", this);
	connect(addJoystickAction, SIGNAL(triggered(bool)),
		this, SLOT(addJoystick()));
}

#include "mainwindow.moc"

