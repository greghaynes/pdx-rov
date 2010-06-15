#include "armjoystick.h"
#include "rovconnection.h"

#include <QDebug>

#define UPDATE_INTERVAL 10
#define MIN 384
#define MAX 1120

ArmJoystick::ArmJoystick(const QString &path,
	RovConnection &conn,
	QObject *parent)
	: RovJoystick(path, conn, parent)
	, flush_timer(new QTimer(this))
{
	elbow = 0;
	wrist = 0;
	shoulder = 0;
	gripper = 0;
	pauldron = 0;
	
	elbow_dirty = false;
	wrist_dirty = false;
	shoulder_dirty = false;
	gripper_dirty = false;
	pauldron_dirty = false;

	connect(flush_timer, SIGNAL(timeout()),
		this, SLOT(flushChanges()));

	flush_timer->setInterval(UPDATE_INTERVAL);
	flush_timer->setSingleShot(false);
	flush_timer->start();
}

void ArmJoystick::onEvent(int type,
	unsigned char number,
	unsigned int time,
	short int value)
{
	switch(type)
	{
		case QJoystick::Axis:
			onAxisEvent(number, value);
			break;
		case QJoystick::Button:
			switch(number)
			{
				case 4:
					if(value)
						gripper = 30000;
					else
						gripper = 0;
					gripper_dirty = true;
					break;
				case 5:
					if(value)
						gripper = -30000;
					else
						gripper = 0;
					gripper_dirty = true;
					break;
			}
	}
}

void ArmJoystick::flushChanges()
{
	if(gripper_dirty)
	{
		updateJoint("gripper", gripper);
		gripper_dirty = false;
	}
	if(wrist_dirty)
	{
		updateJoint("wrist", wrist);
		wrist_dirty = false;
	}
	if(elbow_dirty)
	{
		updateJoint("elbow", elbow);
		elbow_dirty = false;
	}
	if(shoulder_dirty)
	{
		updateJoint("shoulder", shoulder);
		shoulder_dirty = false;
	}
	if(pauldron_dirty)
	{
		updateJoint("pauldron", pauldron);
		pauldron_dirty = false;
	}
}

void ArmJoystick::updateJoint(const QString &joint, int magnitude)
{
	QVariantMap args;
	args.insert("joint", joint);
	if(magnitude > 30000)
		args.insert("magnitude", 100);
	else if(magnitude < -30000)
		args.insert("magnitude", -100);
	else
		args.insert("magnitude", magnitude / 10000);
	connection().sendCommand("arm", "move", args);
}

void ArmJoystick::onAxisEvent(unsigned char number,
	short int value)
{
	switch(number)
	{
		case 0:
			wrist = value;
			wrist_dirty = true;
			break;
		case 1:
			elbow = value;
			elbow_dirty = true;
			break;
		case 2:
			pauldron = value;
			pauldron_dirty = true;
			break;
		case 3:
			shoulder = value;
			shoulder_dirty = true;
			break;
	}
}

#include "armjoystick.moc"

