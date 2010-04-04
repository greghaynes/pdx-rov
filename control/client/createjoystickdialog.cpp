#include "createjoystickdialog.h"
#include "connectionmanager.h"
#include "rovconnection.h"

#include "ui_createjoystickwidget.h"

CreateJoystickDialog::CreateJoystickDialog(QWidget *parent)
	: QDialog(parent)
	, ui(new Ui::CreateJoystickWidget)
	, m_conn_manager(ConnectionManager::instance())
{
	ui->setupUi(this);
	connect(ui->okPushButton, SIGNAL(clicked(bool)),
		this, SLOT(accept()));
	connect(ui->cancelPushButton, SIGNAL(clicked(bool)),
		this, SLOT(reject()));
	connect(ui->addConnectionPushButton, SIGNAL(clicked(bool)),
		m_conn_manager, SLOT(createConnection()));
	connect(m_conn_manager, SIGNAL(connectionAdded(RovConnection&)),
		this, SLOT(connectionAdded(RovConnection&)));

	ui->typeComboBox->addItem("Arm");

	
	RovConnection *conn;
	Q_FOREACH(conn, m_conn_manager->connections())
	{
		connectionAdded(*conn);
	}
}

QString CreateJoystickDialog::path() const
{
	return ui->devicePathLineEdit->text();
}

int CreateJoystickDialog::type() const
{
}

void CreateJoystickDialog::connectionAdded(RovConnection &conn)
{
	ui->connectionComboBox->addItem(conn.label());
}

#include "createjoystickdialog.moc"

