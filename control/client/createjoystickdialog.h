#ifndef CREATE_JOYSTICK_DIALOG
#define CREATE_JOYSTICK_DIALOG

#include <QDialog>

#include "rovjoystick.h"

namespace Ui
{
	class CreateJoystickWidget;
}

class ConnectionManager;

class CreateJoystickDialog
	: public QDialog
{
	Q_OBJECT

	public:
		CreateJoystickDialog(QWidget *parent = 0);

		QString path() const;
		int type() const;

	private Q_SLOTS:
		void connectionAdded(RovConnection &conn);

	private:
		Ui::CreateJoystickWidget *ui;
		ConnectionManager *m_conn_manager;

};

#endif

