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

VarMonitorBuilder::VarMonitorBuilder()
{
}

