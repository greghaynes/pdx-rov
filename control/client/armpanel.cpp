#include "armpanel.h"
#include "servodial.h"

#include <QHBoxLayout>

ArmPanel::ArmPanel(QWidget *parent)
	: QWidget(parent)
{
	setWindowTitle("Arm");

	QHBoxLayout *hlayout = new QHBoxLayout();
	hlayout->addWidget(new ServoDial("Shoulder"));
	hlayout->addWidget(new ServoDial("Elbow"));
	hlayout->addWidget(new ServoDial("Wrist"));
	hlayout->addWidget(new ServoDial("Gripper"));

	setLayout(hlayout);
}

