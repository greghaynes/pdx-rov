#include "motorpanel.h"
#include "motorslider.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>

MotorPanel::MotorPanel(QWidget *parent)
	: QWidget(parent)
{
	setWindowTitle("Propulsion");

	QGroupBox *latGroupBox = new QGroupBox("Lateral Propulsion", this);
	QGroupBox *vertGroupBox = new QGroupBox("Vertical Propulsion", this);

	m_fl = new MotorSlider("FL", this);
	m_fr = new MotorSlider("FR", this);
	m_bl = new MotorSlider("BL", this);
	m_br = new MotorSlider("BR", this);

	QHBoxLayout *latSliderLayout = new QHBoxLayout();
	latSliderLayout->addWidget(m_fl);
	latSliderLayout->addWidget(m_fr);
	latSliderLayout->addWidget(m_bl);
	latSliderLayout->addWidget(m_br);

	latGroupBox->setLayout(latSliderLayout);

	m_ul = new MotorSlider("UL", this);
	m_ur = new MotorSlider("UR", this);
	m_dl = new MotorSlider("DL", this);
	m_dr = new MotorSlider("DR", this);

	QHBoxLayout *vertSliderLayout = new QHBoxLayout();
	vertSliderLayout->addWidget(m_ul);
	vertSliderLayout->addWidget(m_ur);
	vertSliderLayout->addWidget(m_dl);
	vertSliderLayout->addWidget(m_dr);

	vertGroupBox->setLayout(vertSliderLayout);

	QHBoxLayout *vlayout = new QHBoxLayout();
	vlayout->addWidget(latGroupBox);
	vlayout->addWidget(vertGroupBox);

	setLayout(vlayout);
}

