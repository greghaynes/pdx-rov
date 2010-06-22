#include "propjoystick.h"
#include "rovconnection.h"

#include <QDebug>
#include <QTimer>
#include <QVariantMap>

PropJoystick::PropJoystick(const QString &path,
	RovConnection &conn,
	QObject *parent)
	: RovJoystick(path, conn, parent)
{
	forward_axis = 0;
	strafe_axis = 0;
	ascend_axis = 0;
	yaw_axis = 0;
	roll_axis = 0;

	motion_dirty = false;

	connect(&conn, SIGNAL(frozenChanged()),
		this, SLOT(frozenChanged()));
}

void PropJoystick::onEvent(int type,
	unsigned char number,
	unsigned int time,
	short int value)
{
	short int *dir_value = 0;

	switch(type)
	{
		case QJoystick::Axis:
			switch(number)
			{
				case 0:
					dir_value = &strafe_axis;
					break;
				case 1:
					dir_value = &forward_axis;
					value = -value;
					break;
				case 2:
					dir_value = &yaw_axis;
					break;
				case 3:
					dir_value = &ascend_trim_axis; 
					value = -value;
			}
			break;
		case QJoystick::Button:
			switch(number)
			{
				case 2:
				case 3:
					dir_value = &ascend_axis;
					if(value)
						value = -32000;
					break;
				case 4:
				case 5:
					dir_value = &ascend_axis;
					if(value)
						value = 32000;
					break;
			}
			break;
	}
	
	if(dir_value)
	{
		*dir_value = value;
		motion_dirty = true;
	}

	timeout();
}

void PropJoystick::timeout()
{
	if(motion_dirty && !connection().frozen())
	{
		QVariantMap args;
		args.insert("forward", axisToProp(forward_axis));
		args.insert("strafe", axisToProp(strafe_axis));
		args.insert("yaw", axisToProp(yaw_axis));
		args.insert("roll", 0);
		args.insert("ascend", axisToProp(ascend_axis) + axisToProp(ascend_trim_axis));

		connection().sendCommand("propulsion", "move", args);
		motion_dirty = false;
	}
}

void PropJoystick::frozenChanged()
{
	if(connection().frozen())
	{
		QVariantMap args;
		args.insert("forward", 0);
		args.insert("strafe", 0);
		args.insert("yaw", 0);
		args.insert("roll", 0);
		args.insert("ascend", 0);

		connection().sendCommand("propulsion", "move", args);
	}
	else
		timeout();
}

short int PropJoystick::axisToProp(short int axis)
{
	return axis / 128;
}

#include "propjoystick.moc"

