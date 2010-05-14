#include "propjoystick.h"
#include "rovconnection.h"

#include <QDebug>
#include <QTimer>

PropJoystick::PropJoystick(const QString &path,
	RovConnection &conn,
	QObject *parent)
	: RovJoystick(path, conn, parent)
{
	lat_axis_vals[0] = 0;
	lat_axis_vals[1] = 0;
	vert_axis_vals[0] = 0;
	vert_axis_vals[1] = 0;
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
			if(number == 0 || number == 1)
				lat_axis_vals[number] = value;
			else if(number == 2 || number == 3)
				vert_axis_vals[number - 2] = value;
	}
}

void PropJoystick::timeout()
{
	QString pValStr;
	
	if(absmax(lat_axis_vals) > absmax(vert_axis_vals))
	{
		// handle lateral axis
		if(lat_axis_vals[0] == lat_axis_vals[1])
		{
			if(lat_axis_vals[0] == 0)
			{
				connection().setVar("FL", "0");
				connection().setVar("FR", "0");
				connection().setVar("BL", "0");
				connection().setVar("BR", "0");
			}
		}
		else
		{
			if(abs(lat_axis_vals[0]) > abs(lat_axis_vals[1]))
			{
				pValStr = QString::number(joyToPropVal(abs(lat_axis_vals[0])));
				// Moving left-right
				if(lat_axis_vals[0] > 0)
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
				pValStr = QString::number(joyToPropVal(abs(lat_axis_vals[1])));
				// Moving forward-back
				if(lat_axis_vals[1] < 0)
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
	else {
		// handle vertical axis
		if(vert_axis_vals[1] == vert_axis_vals[0])
		{
			if(vert_axis_vals[1] == 0)
			{
				connection().setVar("UL", "0");
				connection().setVar("UR", "0");
				connection().setVar("DL", "0");
				connection().setVar("DR", "0");
				connection().setVar("FL", "0");
				connection().setVar("FR", "0");
				connection().setVar("BL", "0");
				connection().setVar("BR", "0");
			}
		}
		else if(abs(vert_axis_vals[1]) > abs(vert_axis_vals[0]))
		{
			pValStr = QString::number(joyToPropVal(abs(vert_axis_vals[1])));
			if(vert_axis_vals[1] < 0)
			{
				connection().setVar("DL", pValStr);
				connection().setVar("DR", pValStr);
			}
			else
			{
				connection().setVar("UL", pValStr);
				connection().setVar("UR", pValStr);
			}
		}
		else // left/right on vert stick is rotate
		{
			pValStr = QString::number(joyToPropVal(abs(vert_axis_vals[0])));
			if(vert_axis_vals[0] < 0)
			{
				connection().setVar("FR", pValStr);
				connection().setVar("BL", pValStr);
			}
			else
			{
				connection().setVar("FL", pValStr);
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

short int PropJoystick::absmax(short int *vals) const
{
	if(abs(vals[0]) > abs(vals[1]))
		return abs(vals[0]);
	return abs(vals[1]);
}

#include "propjoystick.moc"

