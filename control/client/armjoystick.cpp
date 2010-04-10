#include "armjoystick.h"
#include "rovconnection.h"

#include <QDebug>

ArmJoystick::ArmJoystick(const QString &path,
	RovConnection &conn,
	QObject *parent)
	: RovJoystick(path, conn, parent)
	, flush_timer(new QTimer(this))
{
	connect(flush_timer, SIGNAL(timeout()),
		this, SLOT(flushChanges()));
	connect(&conn, SIGNAL(var(const QString&, const QString&)),
		this, SLOT(gotVarValue(const QString&, const QString&)));
	flush_timer->setInterval(100);
	flush_timer->setSingleShot(false);
	flush_timer->start();
}

void ArmJoystick::onEvent(int type,
	unsigned char number,
	unsigned int time,
	short int value)
{
	switch(type)
	{
		case QJoystick::Axis:
			onAxisEvent(number, value);
	}
}

void ArmJoystick::gotVarValue(const QString &name,
	const QString &value)
{
	m_var_val[name] = value.toInt();
}

void ArmJoystick::flushChanges()
{
	QString key;
	short int newval;
	Q_FOREACH(key, m_latest_var_val.keys())
	{
		unsigned short mot_val = m_latest_var_val[key] / 2000;
		if(mot_val != 0)
		{
			newval = m_var_val[key] + mot_val;
			if(newval > 0 && newval < 180)
			{
				connection().setVar(key, QString::number(newval));
			}
		}
	}
}

void ArmJoystick::onAxisEvent(unsigned char number,
	short int value)
{
	QString var;
	switch(number)
	{
		case 0:
			var = "ArmWrist";
			break;
		case 1:
			var = "ArmElbow";
			value = -value;
			break;
	}

	if(var != "")
	{
		m_latest_var_val[var] = value;
	}
}

#include "armjoystick.moc"

