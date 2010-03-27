#include "rovconnection.h"
#include "varmonitor.h"

RovConnection::RovConnection(QString label,
	QObject *parent)
	: QTcpSocket(parent)
	, m_label(label)
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

void RovConnection::addMonitor(VarMonitor &monitor)
{
	monitors[monitor.name()] = &monitor;
}

const QString &RovConnection::label() const
{
	return m_label;
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

