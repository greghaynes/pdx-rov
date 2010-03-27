#include "rovconnection.h"
#include "varmonitor.h"

#include <QDebug>

RovConnection::RovConnection(QString label,
	QObject *parent)
	: QTcpSocket(parent)
	, m_label(label)
{
	connect(this, SIGNAL(readyRead()),
		this, SLOT(dataRecieved()));
}

RovConnection::~RovConnection()
{
	VarMonitor *m;
	Q_FOREACH(m, monitor_list)
		delete m;
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
	monitors[monitor.name()].append(&monitor);
	monitor_list.append(&monitor);
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
	if(eqindex != -1)
	{
		vr = line.left(eqindex);
		va = line.right(line.size() - eqindex - 1);
		va.chop(1);
		QList<VarMonitor*> ms = monitors[vr];
		VarMonitor *m;
		Q_FOREACH(m, ms)
		{
			m->gotValue(va);
		}
		emit(var(vr, va));
	}
}

#include "rovconnection.moc"

