#ifndef JOYSTICKS_MODEL
#define JOYSTICKS_MODEL

#include <QStandardItemModel>

class QJoystick;

class JoystickItem
	: public QObject,
	  public QStandardItem
{
	Q_OBJECT

	public:
		JoystickItem(QJoystick &joystick);

	private Q_SLOTS:
		

	private:
		QJoystick *m_joystick;

};

class JoysticksModel
	: public QStandardItemModel
{
	Q_OBJECT

	public:
		JoysticksModel(QObject *parent = 0);

	public Q_SLOTS:
		void addJoystick(QJoystick &joystick);

};

#endif

