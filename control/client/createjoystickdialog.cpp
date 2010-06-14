#include "createjoystickdialog.h"
#include "rovconnection.h"
#include "rovjoystick.h"

#include "ui_createjoystickwidget.h"

CreateJoystickDialog::CreateJoystickDialog(QWidget *parent)
	: QDialog(parent)
	, ui(new Ui::CreateJoystickWidget)
{
	ui->setupUi(this);
	connect(ui->okPushButton, SIGNAL(clicked(bool)),
		this, SLOT(accept()));
	connect(ui->cancelPushButton, SIGNAL(clicked(bool)),
		this, SLOT(reject()));

	ui->typeComboBox->addItem("Arm");
	ui->typeComboBox->addItem("Propulsion");
}

QString CreateJoystickDialog::path() const
{
	return ui->devicePathLineEdit->text();
}

int CreateJoystickDialog::type() const
{
	if(ui->typeComboBox->currentIndex() != 0)
		return RovJoystick::Propulsion;
	return RovJoystick::Arm;
}

#include "createjoystickdialog.moc"

