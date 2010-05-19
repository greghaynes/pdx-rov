#include "sensorpanel.h"

#include "ui_sensorspanel.h"

SensorPanel::SensorPanel(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::SensorsPanel)
{
	setWindowTitle("Sensors");

	ui->setupUi(this);	
}

