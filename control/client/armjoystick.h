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
		void flushChanges();

	private:
		void onAxisEvent(unsigned char number,
			short int value);
		void updateJoint(const QString &joint,
			int magnitude);

		QTimer *flush_timer;

		short int elbow;
		short int wrist;
		short int shoulder;
		short int gripper;
		short int pauldron;

		bool elbow_dirty;
		bool wrist_dirty;
		bool shoulder_dirty;
		bool gripper_dirty;
		bool pauldron_dirty;
};

#endif

