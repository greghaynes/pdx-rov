#ifndef ROV_JOYSTICK_H
#define ROV_JOYSTICK_H

#include "qjoystick.h"

class RovConnection;

class RovJoystick
	: public QJoystick
{

	public:
		RovJoystick(const QString &path,
			QObject *parent = 0);

		RovConnection &connection();

		void onJoystickEvent(int type,
			unsigned char number,
			unsigned int time,
			short int val);

	protected:
		void onEvent(int type,
			unsigned char number,
			unsigned int time,
			short int val);

	private:
		RovConnection *m_conn;

};

#endif

