#include "rovjoystick.h"
#include "rovconnection.h"
#include "qjoystick.h"

RovJoystick::RovJoystick(const QString &path,
	QObject *parent)
	: QJoystick(path, parent)
	, m_conn(new RovConnection(this))
{
	connect(this, SIGNAL(eventOccurred(
			EventType, unsigned char, unsigned int, short int)),
		this, SLOT(onJoystickEvent(	
			EventType, unsigned char, unsigned int, short int)));
}

RovConnection &RovJoystick::connection()
{
	return *m_conn;
}

void RovJoystick::onJoystickEvent(EventType type,
	unsigned char number,
	unsigned int time,
	short int val)
{
	QString var;
	switch(type)
	{
		Button:
			var = "Button";
			break;
		Axis:
			var = "Axis";
			break;
		default:
			var = "Unknown";
	}
	var.append(QString::number(number));
	m_conn->setVar(var, QString::number(val));
}

#include "rovjoystick.moc"

