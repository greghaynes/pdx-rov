#include "servodial.h"

#include <QVBoxLayout>
#include <QLabel>
#include <QDial>

ServoDial::ServoDial(const QString &name,
	QWidget *parent)
	: QWidget(parent)
{
	m_dial = new QDial(this);

	QVBoxLayout *vlayout = new QVBoxLayout();
	vlayout->addWidget(new QLabel(name));
	vlayout->addWidget(m_dial);

	setLayout(vlayout);
}

QDial &ServoDial::dial()
{
	return *m_dial;
}

