#include "rovconnection.h"
#include "varmonitor.h"

#include <QByteArray>

#include <QDebug>

RovConnection::RovConnection(QString label,
	QObject *parent)
	: QTcpSocket(parent)
	, m_label(label)
{
	connect(this, SIGNAL(readyRead()),
		this, SLOT(dataReceived()));
}

RovConnection::~RovConnection()
{
}

void RovConnection::sendCommand(const QString &module,
	const QString &command,
	QVariantMap &arguments)
{
	QVariantMap request;
	QVariantMap command_map;
	command_map.insert("module", module);
	command_map.insert("command", command);
	command_map.insert("arguments", arguments);
	request.insert("command", command_map);
	QByteArray json = json_serializer.serialize(request);
	write(json);
	write("\n\n");
}

const QString &RovConnection::label() const
{
	return m_label;
}

void RovConnection::dataReceived()
{
	bool ok;
	QByteArray data = read(4096);

	QVariant parsed = json_parser.parse(data, &ok);
	QVariantMap response = parsed.toMap();
	
	if(!ok)
	{
		qDebug() << "Invalid response, ditching it: ";
		qDebug() << data;
	}
	else
	{
		QVariantMap command = response["command"].toMap();
		QString module = command["module"].toString();
		QString command_name = command["command"].toString();
		QVariantMap arguments = command["arguments"].toMap();
		emit(receivedCommand(module, command_name, arguments));
	}
}

#include "rovconnection.moc"

