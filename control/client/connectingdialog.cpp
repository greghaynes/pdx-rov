#include "connectingdialog.h"

#include <QLabel>
#include <QErrorMessage>

ConnectingDialog::ConnectingDialog(QWidget *parent)
	: QProgressDialog(parent)
{
	setMaximum(1);
	setMinimum(0);
	setWindowTitle("Establishing Connection");
	setLabel(new QLabel("No connection initialized."));
}

bool ConnectingDialog::waitForConnectionOn(QTcpSocket &connection)
{
	setValue(0);
	setLabel(new QLabel("Connecting to ROV..."));
	connection.connectToHost("rov", 8080);
	exec();
	return true;
}

void ConnectingDialog::connected()
{
	setValue(1);
	accept();
}

void ConnectingDialog::error(QAbstractSocket::SocketError socketError)
{
	QErrorMessage *msgD = new QErrorMessage();
	QString msg = "Connection error: ";
	switch(socketError)
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
	reject();
}

#include "connectingdialog.moc"
