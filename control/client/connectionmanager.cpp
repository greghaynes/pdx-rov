#include "connectionmanager.h"
#include "rovconnection.h"

#include "ui_createconnectionwidget.h"

#include <QErrorMessage>

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

ConnectionManager *ConnectionManager::instance()
{
	static ConnectionManager *m;
	if(!m)
		m = new ConnectionManager();
	return m;
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
		connect(conn, SIGNAL(error(QAbstractSocket::SocketError)),
			this, SLOT(connectionError(QAbstractSocket::SocketError)));
	}
}

void ConnectionManager::connectionError(QAbstractSocket::SocketError error)
{
	QErrorMessage *msgD = new QErrorMessage();
	QString msg = "Connection error: ";
	switch(error)
	{
		case QAbstractSocket::HostNotFoundError:
			msg.append("Host not found");
			break;
		case QAbstractSocket::ConnectionRefusedError:
			msg.append("Connection refused");
			break;
		case QAbstractSocket::RemoteHostClosedError:
			msg.append("Remote host closed the connection");
	}
	msgD->showMessage(msg);
	msgD->exec();
}

ConnectionManager::ConnectionManager()
{
}

#include "connectionmanager.moc"

