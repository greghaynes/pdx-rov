#ifndef Q_JOYSTICK_H
#define Q_JOYSTICK_H

#include <QObject>
#include <QFileSystemWatcher>

#include <joystick.h>
#include <joystick.cpp>

class QJoystick
  : public QObject
{
	Q_OBJECT

	public:
		enum EventType
		{
		  BUTTON,
		  AXES
		};

		QJoystick(const QUrl &path, QObject *parent = 0);
		QString name();
		QString device();
		int numButtons();
		int numAxes();

	Q_SIGNALS:
		void eventOccurred(EventType type,
			unsigned char number,
			unsigned int time,
			short int value);

	private Q_SLOTS:
		void onChanged(const QString &path);
  
	private:
		QFileSystemWatcher *filesysWatcher;

};

#endif Q_JOYSTICK_H
