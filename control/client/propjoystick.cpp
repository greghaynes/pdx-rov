#include "propjoystick.h"
#include "rovconnection.h"

#include <QDebug>
#include <QTimer>

PropJoystick::PropJoystick(const QString &path,
	RovConnection &conn,
	QObject *parent)
	: RovJoystick(path, conn, parent)
{
	axis_vals[0] = 0;
	axis_vals[1] = 0;
	axis_vals[2] = 0;
	axis_vals[3] = 0;
	QTimer *timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()),
		this, SLOT(timeout()));
	timer->setInterval(100);
	timer->setSingleShot(false);
	timer->start();
}

void PropJoystick::onEvent(int type,
	unsigned char number,
	unsigned int time,
	short int value)
{
	switch(type)
	{
		case QJoystick::Axis:
			axis_vals[number] = value;
	}
}

void PropJoystick::timeout()
{
	if(axis_vals[0] == axis_vals[1])
	{
		if(axis_vals[0] == 0)
		{
			connection().setVar("FL", "0");
			connection().setVar("FR", "0");
			connection().setVar("BL", "0");
			connection().setVar("BR", "0");
		}
	}
	else
	{
		QString pValStr;
		if(abs(axis_vals[0]) > abs(axis_vals[1]))
		{
			pValStr = QString::number(joyToPropVal(axis_vals[0]));
			// Moving left-right
			if(axis_vals[0] > 0)
			{
				// Right
				connection().setVar("FL", pValStr);
				connection().setVar("BL", pValStr);
			}
			else
			{
				// Left
				connection().setVar("FR", pValStr);
				connection().setVar("BR", pValStr);
			}
		}
		else
		{
			pValStr = QString::number(joyToPropVal(axis_vals[1]));
			// Moving forward-back
			if(axis_vals[1] < 0)
			{
				// Forward
				connection().setVar("FL", pValStr);
				connection().setVar("FR", pValStr);
			}
			else
			{
				// Back
				connection().setVar("BL", pValStr);
				connection().setVar("BR", pValStr);
			}
		}
	}
}

short int PropJoystick::joyToPropVal(short int joyVal) const
{
	return joyVal / 70;
}

short int PropJoystick::abs(short int val) const
{
	if(val < 0)
		return -val;
}

#include "propjoystick.moc"

