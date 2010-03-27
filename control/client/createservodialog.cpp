#include "createservodialog.h"
#include "connectionmanager.h"
#include "rovconnection.h"

#include <QVariant>
#include <QHostAddress>

#include "ui_createservowidget.h"

CreateServoDialog::CreateServoDialog(ConnectionManager &conn_manager,
	QWidget *parent)
	: QDialog(parent)
	, ui(new Ui::CreateServoWidget)
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

QString CreateServoDialog::name()
{
	return ui->nameLineEdit->text();
}

RovConnection &CreateServoDialog::connection()
{
	return *m_conn_manager->connections()[ui->connectionComboBox->currentIndex()];
}

void CreateServoDialog::connectionAdded(RovConnection &conn)
{
	ui->connectionComboBox->addItem(conn.label());
}

#include "createservodialog.moc"

