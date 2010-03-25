#include "createjoystickdialog.h"

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
}

QString CreateJoystickDialog::path() const
{
	return ui->devicePathLineEdit->text();
}

