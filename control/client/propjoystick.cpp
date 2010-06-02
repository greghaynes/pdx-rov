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

	QTimer *timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()),
		this, SLOT(timeout()));
	timer->setInterval(10);
	timer->setSingleShot(false);
	timer->start();
}

void PropJoystick::onEvent(int type,
	unsigned char number,
	unsigned int time,
	short int value)
{
	short int *dir_value;

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
					break;
				case 2:
					dir_value = &yaw_axis;
					break;
				case 3:
					dir_value = &ascend_axis;
					break;
			}
			break;
	}

	*dir_value = value;
	motion_dirty = true;
}

void PropJoystick::timeout()
{
	if(motion_dirty)
	{
		QVariantMap args;
		args.insert("forward", axisToProp(forward_axis));
		args.insert("strafe", axisToProp(strafe_axis));
		args.insert("yaw", axisToProp(yaw_axis));
		args.insert("ascend", axisToProp(ascend_axis));

		connection().sendCommand("propulsion", "move", args);
		motion_dirty = false;
	}
}

short int PropJoystick::axisToProp(short int axis)
{
	return axis / 128;
}

#include "propjoystick.moc"

