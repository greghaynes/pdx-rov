#include "servowidget.h"

#include <QVBoxLayout>
#include <QDebug>

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
	mainVLayout->addWidget(new QLabel(name, this));
	m_str_pos = QString::number(m_pos);
	posLabel = new QLabel(m_str_pos, this);
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
	m_str_pos = QString::number(val);
	posLabel->setText(m_str_pos);
}

void ServoWidget::gotValue(const QString &value)
{
	setPos(value.toInt());
	qDebug() << "Got value " << value;
}

