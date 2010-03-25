#ifndef JOYSTICK_MANAGER_H
#define JOYSTICK_MANAGER_H

#include <QObject>

class JoystickManager
	: public QObject
{

	public:
		JoystickManager(QObject *parent);

		virtual void addJoystick(QString &dev_path);
		QList<QJoystick> &joysticks();

	private:
		QList<QJoystick*> m_joysticks;

}

#endif

