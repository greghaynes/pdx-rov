#ifndef MOTOR_PANEL_H
#define MOTOR_PANEL_H

#include <QWidget>

class MotorSlider;

class MotorPanel
	: public QWidget
{

	public:
		MotorPanel(QWidget *parent = 0);

	private:
		MotorSlider *m_fl;
		MotorSlider *m_fr;
		MotorSlider *m_bl;
		MotorSlider *m_br;
		MotorSlider *m_ul;
		MotorSlider *m_dl;
		MotorSlider *m_ur;
		MotorSlider *m_dr;
		
};

#endif

