#include "rovjoystick.h"
#include "rovconnection.h"
#include "qjoystick.h"

#include <QDebug>

RovJoystick::RovJoystick(const QString &path,
	QObject *parent)
	: QJoystick(path, parent)
	, m_conn(new RovConnection(this))
{
	connect(this, SIGNAL(eventOccurred(
			int, unsigned char, unsigned int, short int)),
		this, SLOT(onJoystickEvent(	
			int, unsigned char, unsigned int, short int)));
}

RovConnection &RovJoystick::connection()
{
	return *m_conn;
}

void RovJoystick::onJoystickEvent(int type,
	unsigned char number,
	unsigned int time,
	short int val)
{
	QString var;
	if(type == QJoystick::Button)
			var = "Button";
	else if(type == QJoystick::Axis)
			var = "Axis";
	else
			var = "Unknown";
	var.append(QString::number(number));
	m_conn->setVar(var, QString::number(val));
}

#include "rovjoystick.moc"

