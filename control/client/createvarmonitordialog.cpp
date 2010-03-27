#include "createvarmonitordialog.h"
#include "connectionmanager.h"
#include "rovconnection.h"

#include <QVariant>
#include <QHostAddress>

#include "ui_createvarmonitorwidget.h"

CreateVarMonitorDialog::CreateVarMonitorDialog(ConnectionManager &conn_manager,
	QWidget *parent)
	: QDialog(parent)
	, ui(new Ui::CreateVarMonitorWidget)
	, m_conn_manager(&conn_manager)
{
	ui->setupUi(this);

	connect(ui->okPushButton, SIGNAL(clicked(bool)),
		this, SLOT(accept()));
	connect(ui->cancelPushButton, SIGNAL(clicked(bool)),
		this, SLOT(reject()));
	connect(ui->addConnectionPushButton, SIGNAL(clicked(bool)),
		&conn_manager, SLOT(createConnection()));
	connect(&conn_manager, SIGNAL(connectionAdded(RovConnection&)),
		this, SLOT(connectionAdded(RovConnection&)));

	RovConnection *conn;
	Q_FOREACH(conn, conn_manager.connections())
	{
		connectionAdded(*conn);
	}
}

QString CreateVarMonitorDialog::name()
{
	return ui->nameLineEdit->text();
}

RovConnection &CreateVarMonitorDialog::connection()
{
	return *m_conn_manager->connections()[ui->connectionComboBox->currentIndex()];
}

void CreateVarMonitorDialog::connectionAdded(RovConnection &conn)
{
	ui->connectionComboBox->addItem(conn.label());
}

#include "createvarmonitordialog.moc"

