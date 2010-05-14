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
		short int abs(short int) const;
		short int joyToPropVal(short int) const;
		short int absmax(short int*) const;

		short int vert_axis_vals[2];
		short int lat_axis_vals[2];

};

#endif

