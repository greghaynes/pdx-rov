#include "servowidget.h"

#include <QVBoxLayout>
#include <QDebug>

#include "rovconnection.h"

ServoWidget::ServoWidget(const QString &name,
	const QString &var_name,
	RovConnection &conn,
	QWidget *parent)
	: QWidget(parent)
	, VarMonitor(var_name)
	, m_max(0)
	, m_min(0)
	, m_pos(0)
	, m_conn(&conn)
{
	QVBoxLayout *mainVLayout = new QVBoxLayout(this);
	mainVLayout->addWidget(new QLabel(name, this));
	m_str_pos = QString::number(m_pos);
	posLabel = new QLabel(m_str_pos, this);
	mainVLayout->addWidget(posLabel);
	setLayout(mainVLayout);
	m_conn->reqVar(var_name);
}

ServoWidget::~ServoWidget()
{
	m_conn->removeMonitor(*this);
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
}

#include "servowidget.moc"

