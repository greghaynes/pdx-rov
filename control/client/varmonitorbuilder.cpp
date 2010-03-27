#include "varmonitorbuilder.h"
#include "rovconnection.h"

#include <QAbstractSocket>
#include <QErrorMessage>

VarMonitorBuilder &VarMonitorBuilder::instance()
{
	static VarMonitorBuilder *builder;
	if(!builder)
		builder = new VarMonitorBuilder();
	return *builder;
}

void VarMonitorBuilder::createVarMonitor(RovConnection &conn,
	const QString &var)
{
	if(conn.state() != QAbstractSocket::ConnectedState)
	{
		QErrorMessage *msg = new QErrorMessage();
		msg->showMessage("Cannot monitor a variable on an unconnected connection.");
		msg->exec();
	}
	else
	{
	}
}

QWidget *VarMonitorBuilder::buildVarMonitor(RovConnection &conn,
	const QString &var,
	const QString &type)
{
	return 0;
}

void VarMonitorBuilder::varTypeResponse(const QString &var,
	const QString &type)
{
}

void VarMonitorBuilder::connectionAdded(RovConnection &conn)
{
	connect(&conn, SIGNAL(queryType(const QString&, const QString&)),
		this, SLOT(varTypeResponse(const QString&, const QString&)));
}

VarMonitorBuilder::VarMonitorBuilder()
{
}

#include "varmonitorbuilder.moc"

