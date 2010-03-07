#include "rovconnection.h"

RovConnection::RovConnection(QObject *parent)
	: QTcpSocket(parent)
{
}

bool RovConnection::setVar(const QString &name,
	const QString &value)
{
	QString send;
	if(state() == ConnectedState)
	{
		send = name;
		send.append("=");
		send.append(value);
		write(send.toAscii());
		return true;
	}
	return false;
}

bool RovConnection::reqVar(const QString &name)
{
	QString send;
	if(state() == ConnectedState)
	{
		send = name;
		send.append("?");
		write(send.toAscii());
		return true;
	}
	return false;
}

void RovConnection::dataRecieved()
{
	QString line = readLine();
	QString vr, va;

	int eqindex = line.indexOf('=');
	vr = line.left(eqindex);
	va = line.right(eqindex+1);
	emit(var(vr, va));
}

#include "rovconnection.moc"

