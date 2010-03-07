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
		QString name() const;
		QString device() const;
		int numButtons() const;
		int numAxis() const;

	Q_SIGNALS:
		/**
		 * @brief Number of buttons available has changed.
		 *
		 * When emitted, numButtons is set to the new value of
		 * buttons.
		 */
		void numButtonsChanged(int old_val);

		/**
		 * @brief Number of axis available has changed.
		 *
		 * When emitted, numAxis is set to the new value of
		 * buttons.
		 */
		void numAxisChanged(int old_val);

		void eventOccurred(int type,
			unsigned char number,
			unsigned int time,
			short int value);

	private Q_SLOTS:
		void setNumButtons(int);
		void setNumAxis(int);
		void activated(int);
  
	private:
		int num_buttons;
		int num_axis;
		QSocketNotifier *socketNotifier;

};

#endif
