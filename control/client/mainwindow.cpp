#include "mainwindow.h"
#include "joysticksmodel.h"
#include "rovconnection.h"

#include <QVBoxLayout>
#include <QMenu>
#include <QMenuBar>

MainWindow::MainWindow(RovConnection &conn,
	QWidget *parent)
	: QMainWindow(parent)
	, m_connection(&conn)
{
	m_joysticksModel = new JoysticksModel(this);
	setupActions();
	setupMenus();
	setupToolbars();
}

JoysticksModel &MainWindow::joysticksModel()
{
	return *m_joysticksModel;
}

void MainWindow::setupToolbars()
{
	m_toolBar = new QToolBar(this);

	m_toolBar->addAction(freezeAction);

	addToolBar(Qt::TopToolBarArea, m_toolBar);
}

void MainWindow::setupMenus()
{
	QMenu *fileMenu = new QMenu("&File", this);
	
	menuBar()->addMenu(fileMenu);
}

void MainWindow::setupActions()
{
	quitAction = new QAction("&Quit", this);
	quitAction->setShortcut(QKeySequence::Close);
	connect(quitAction, SIGNAL(triggered(bool)),
		this, SLOT(close()));

	freezeAction = new QAction("Free&ze",  this);
	freezeAction->setCheckable(true);
	freezeAction->setChecked(false);
	connect(freezeAction, SIGNAL(triggered(bool)),
		m_connection, SLOT(setFrozen(bool)));
}

