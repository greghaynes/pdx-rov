#ifndef ARM_JOYSTICK_H
#define ARM_JOYSTICK_H

#include "rovjoystick.h"

#include <QHash>
#include <QString>
#include <QTimer>

class ArmJoystick
	: public RovJoystick
{
	Q_OBJECT

	public:
		ArmJoystick(const QString &path,
			RovConnection &conn,
			QObject *parent = 0);

	protected:
		void onEvent(int type,
			unsigned char number,
			unsigned int time,
			short int value);

	private Q_SLOTS:
		void gotVarValue(const QString &name,
			const QString &value);
		void flushChanges();

	private:
		void onAxisEvent(unsigned char number,
			short int value);

		QHash<QString, short int> m_var_val;
		QHash<QString, short int> m_latest_var_val;
		QTimer *flush_timer;

};

#endif

