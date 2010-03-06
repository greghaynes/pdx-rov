#include "qjoystick.h"

#include <QDebug>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <linux/joystick.h>

QJoystick::QJoystick(const QString &path,
	QObject *parent)
	: QObject(parent)
	, num_buttons(0)
	, num_axis(0)
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

int QJoystick::numButtons() const
{
	return num_buttons;
}

int QJoystick::numAxis() const
{
	return num_axis;
}

void QJoystick::setNumButtons(int num)
{
	int old_count;
	if(num_buttons < num)
	{
		old_count = num_buttons;
		num_buttons = num;
		emit(numButtonsChanged(old_count));
	}
}

void QJoystick::setNumAxis(int num)
{
	int old_count;
	if(num_axis < num)
	{
		old_count = num_axis;
		num_axis = num;
		emit(numAxisChanged(old_count));
	}
}

void QJoystick::activated(int fd)
{
	static int len;
	static struct js_event ev;
	EventType type;

	len = read(fd, &ev, sizeof(struct js_event));
	if(len == -1 || len != sizeof(struct js_event))
	{
		qDebug() << "Invalid read length for joystick event.";
		return;
	}

	if(ev.type & JS_EVENT_INIT)
	{
		ev.type = ev.type & (~JS_EVENT_INIT);
		switch(ev.type)
		{
			case JS_EVENT_BUTTON:
				qDebug() << "Init button " << ev.number;
				setNumButtons(ev.number+1);
			case JS_EVENT_AXIS:
				qDebug() << "Init axis " << ev.number;
				setNumAxis(ev.number+1);
		}
	}
	else
	{
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
}

