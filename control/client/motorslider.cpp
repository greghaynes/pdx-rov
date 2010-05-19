#include "motorslider.h"

#include <QVBoxLayout>
#include <QLabel>
#include <QSlider>
#include <QCheckBox>

MotorSlider::MotorSlider(const QString &name,
	QWidget *parent)
	: QWidget(parent)
{
	m_slider = new QSlider(this);
	m_slider->setOrientation(Qt::Vertical);

	m_checkbox = new QCheckBox(this);

	QVBoxLayout *vlayout = new QVBoxLayout();
	vlayout->addWidget(new QLabel(name));
	vlayout->addWidget(m_slider);
	vlayout->addWidget(m_checkbox);

	setLayout(vlayout);
}

QSlider &MotorSlider::slider()
{
	return *m_slider;
}

