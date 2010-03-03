#include "qjoystick.h"

#include <QDebug>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <linux/joystick.h>

QJoystick::QJoystick(const QString &path,
	QObject *parent)
	: QObject(parent)
	, socketNotifier(0)
{
	int fd;
	fd = open(path.toAscii(), O_RDONLY);
	if(fd != -1)
	{
		socketNotifier = new QSocketNotifier(fd, QSocketNotifier::Read, this);
		connect(socketNotifier, SIGNAL(activated(int)),
			this, SLOT(activated(int)));
	}
}

QString QJoystick::name()
{
	return "";
}

QString QJoystick::device()
{
	return "";
}

int QJoystick::numButtons()
{
	return 0;
}

int QJoystick::numAxis()
{
	return 0;
}

void QJoystick::activated(int fd)
{
	static int len;
	static struct js_event ev;
	EventType type;

	qDebug() << "Retrieved joystick event.";
	len = read(fd, &ev, sizeof(struct js_event));
	if(len == -1 || len != sizeof(struct js_event))
	{
		qDebug() << "Invalid read length for joystick event.";
		return;
	}

	// Set our event type
	switch(ev.type)
	{
		case JS_EVENT_BUTTON:
			type = Button;
			break;
		case JS_EVENT_AXIS:
			type = Axis;
			break;
		default:
			type = Init;
	}

	emit(eventOccurred(type, ev.number, ev.time, ev.value));
}

