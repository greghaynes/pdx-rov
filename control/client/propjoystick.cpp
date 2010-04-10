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
		if(abs(axis_vals[0]) > abs(axis_vals[1]))
		{
			// Moving left-right
			if(axis_vals[0] > 0)
			{
				// Right
				connection().setVar("FL", "400");
				connection().setVar("BL", "400");
			}
			else
			{
				// Left
				connection().setVar("FR", "400");
				connection().setVar("BR", "400");
			}
		}
		else
		{
			// Moving forward-back
			if(axis_vals[1] < 0)
			{
				// Forward
				connection().setVar("FL", "400");
				connection().setVar("FR", "400");
			}
			else
			{
				// Back
				connection().setVar("BL", "400");
				connection().setVar("BR", "400");
			}
		}
	}
}

short int PropJoystick::abs(short int val)
{
	if(val < 0)
		return -val;
}

#include "propjoystick.moc"

