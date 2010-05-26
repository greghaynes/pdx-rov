#include "armpanel.h"
#include "servodial.h"

#include <QVBoxLayout>

ArmPanel::ArmPanel(QWidget *parent)
	: QWidget(parent)
{
	setWindowTitle("Arm");

	QVBoxLayout *hlayout = new QVBoxLayout();
	hlayout->addWidget(new ServoDial("Shoulder"));
	hlayout->addWidget(new ServoDial("Elbow"));
	hlayout->addWidget(new ServoDial("Wrist"));
	hlayout->addWidget(new ServoDial("Gripper"));

	setLayout(hlayout);
}

