#ifndef Q_JOYSTICK_H
#define Q_JOYSTICK_H

#include <QObject>
#include <QString>
#include <QSocketNotifier>

class QJoystick
  : public QObject
{
	Q_OBJECT

	public:
		enum EventType
		{
			Button,
			Axis,
			Init,
		};

		QJoystick(const QString &path, QObject *parent = 0);
		QString name();
		QString device();
		int numButtons();
		int numAxis();

	Q_SIGNALS:
		void eventOccurred(EventType type,
			unsigned char number,
			unsigned int time,
			short int value);

	private Q_SLOTS:
		void activated(int);
  
	private:
		QSocketNotifier *socketNotifier;

};

#endif
