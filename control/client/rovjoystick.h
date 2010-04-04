#ifndef ROV_JOYSTICK_H
#define ROV_JOYSTICK_H

#include "qjoystick.h"

class RovConnection;

class RovJoystick
	: public QJoystick
{

	public:
		enum ControlType
		{
			Arm,
			Propulsion
		};

		RovJoystick(const QString &path,
			RovConnection &conn,
			QObject *parent = 0);

		RovConnection &connection();

	protected:
		void onEvent(int type,
			unsigned char number,
			unsigned int time,
			short int val);

	private:
		RovConnection *m_conn;

};

#endif

