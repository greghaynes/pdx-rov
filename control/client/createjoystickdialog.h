#ifndef CREATE_JOYSTICK_DIALOG
#define CREATE_JOYSTICK_DIALOG

#include <QDialog>

namespace Ui
{
	class CreateJoystickWidget;
}

class ConnectionManager;
class RovConnection;

class CreateJoystickDialog
	: public QDialog
{
	Q_OBJECT

	public:
		CreateJoystickDialog(QWidget *parent = 0);

		QString path() const;
		int type() const;
		RovConnection &connection();

	private Q_SLOTS:
		void connectionAdded(RovConnection &conn);

	private:
		Ui::CreateJoystickWidget *ui;
		ConnectionManager *m_conn_manager;

};

#endif

