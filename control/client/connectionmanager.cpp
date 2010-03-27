#include "connectionmanager.h"
#include "rovconnection.h"

#include "ui_createconnectionwidget.h"

CreateConnectionDialog::CreateConnectionDialog(QWidget *parent)
	: QDialog(parent)
	, ui(new Ui::CreateConnectionWidget)
{
	ui->setupUi(this);

	connect(ui->okPushButton, SIGNAL(clicked(bool)),
		this, SLOT(accept()));
	connect(ui->cancelPushButton, SIGNAL(clicked(bool)),
		this, SLOT(reject()));
}

QString CreateConnectionDialog::label()
{
	return ui->labelLineEdit->text();
}

QString CreateConnectionDialog::hostname()
{
	return ui->hostnameLineEdit->text();
}

QString CreateConnectionDialog::port()
{
	return ui->portLineEdit->text();
}

ConnectionManager::ConnectionManager()
{
}

QList<RovConnection*> &ConnectionManager::connections()
{
	return m_connections;
}

void ConnectionManager::createConnection()
{
	CreateConnectionDialog *d = new CreateConnectionDialog();
	if(d->exec())
	{
		RovConnection *conn = new RovConnection(d->label(), this);
		m_connections.append(conn);
		conn->connectToHost(d->hostname(),
			d->port().toInt());
		emit(connectionAdded(*conn));
	}
}

#include "connectionmanager.moc"

