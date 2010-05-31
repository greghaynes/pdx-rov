#ifndef PROP_JOYSTICK_H
#define PROP_JOYSTICK_H

#include "rovjoystick.h"

class RovConnection;

class PropJoystick
	: public RovJoystick
{
	Q_OBJECT

	public:
		PropJoystick(const QString &path,
			RovConnection &conn,
			QObject *parent = 0);

	protected:
		void onEvent(int type,
			unsigned char number,
			unsigned int time,
			short int value);

	private Q_SLOTS:
		void timeout();

	private:
		short int axisToProp(short int);

		short int forward_axis;
		short int strafe_axis;
		short int ascend_axis;
		short int yaw_axis;
		short int roll_axis;

};

#endif

