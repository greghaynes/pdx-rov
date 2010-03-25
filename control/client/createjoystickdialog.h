#ifndef CREATE_JOYSTICK_DIALOG
#define CREATE_JOYSTICK_DIALOG

#include <QDialog>

namespace Ui
{
	class CreateJoystickWidget;
}

class CreateJoystickDialog
	: public QDialog
{

	public:
		CreateJoystickDialog(QWidget *parent = 0);

		QString path() const;

	private:
		Ui::CreateJoystickWidget *ui;

};

#endif

