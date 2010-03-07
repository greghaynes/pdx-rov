#ifndef ROV_JOYSTICK_H
#define ROV_JOYSTICK_H

#include "qjoystick.h"

class RovConnection;

class RovJoystick
	: public QJoystick
{
	Q_OBJECT

	public:
		RovJoystick(const QString &path,
			QObject *parent = 0);

		RovConnection &connection();

	private Q_SLOTS:
		void onJoystickEvent(int type,
			unsigned char number,
			unsigned int time,
			short int val);

	private:
		RovConnection *m_conn;

};

#endif

