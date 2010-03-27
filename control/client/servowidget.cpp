#include "servowidget.h"

#include <QVBoxLayout>

ServoWidget::ServoWidget(const QString &name,
	const QString &var_name,
	QWidget *parent)
	: QWidget(parent)
	, VarMonitor(var_name)
	, m_max(0)
	, m_min(0)
	, m_pos(0)
{
	QVBoxLayout *mainVLayout = new QVBoxLayout(this);
	mainVLayout->addWidget(new QLabel(name));
	posLabel = new QLabel(QString(m_pos));
	mainVLayout->addWidget(posLabel);
	setLayout(mainVLayout);
}

int ServoWidget::max() const
{
	return m_max;
}

int ServoWidget::min() const
{
	return m_min;
}

int ServoWidget::pos() const
{
	return m_pos;
}

void ServoWidget::setPos(int val)
{
	m_pos = val;
	posLabel->setText(QString(val));
}

void ServoWidget::gotValue(const QString &value)
{
	setPos(value.toInt());
}

