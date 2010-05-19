#ifndef SERVO_DIAL_H
#define SERVO_DIAL_H

#include <QWidget>

class QDial;

class ServoDial
	: public QWidget
{

	public:
		ServoDial(const QString &name,
			QWidget *parent = 0);

		QDial &dial();

	private:
		QDial *m_dial;

};

#endif

