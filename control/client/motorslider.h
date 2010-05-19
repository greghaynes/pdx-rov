#ifndef MOTOR_SLIDER_H
#define MOTOR_SLIDER_H

#include <QWidget>

class QSlider;
class QCheckBox;

class MotorSlider
	: public QWidget
{

	public:
		MotorSlider(const QString &name,
			QWidget *parent = 0);

		QSlider &slider();

	private:
		QSlider *m_slider;
		QCheckBox *m_checkbox;

};

#endif

