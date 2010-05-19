#ifndef SENSOR_PANEL_H
#define SENSOR_PANEL_H

#include <QWidget>

namespace Ui
{
	class SensorsPanel;
}

class SensorPanel
	: public QWidget
{

	public:
		SensorPanel(QWidget *parent = 0);

	private:
		Ui::SensorsPanel *ui;

};

#endif

