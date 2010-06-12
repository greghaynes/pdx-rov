#ifndef CREATE_JOYSTICK_DIALOG
#define CREATE_JOYSTICK_DIALOG

#include <QDialog>

namespace Ui
{
	class CreateJoystickWidget;
}
class RovConnection;

class CreateJoystickDialog
	: public QDialog
{
	Q_OBJECT

	public:
		CreateJoystickDialog(QWidget *parent = 0);

		QString path() const;
		int type() const;

	private:
		Ui::CreateJoystickWidget *ui;

};

#endif

