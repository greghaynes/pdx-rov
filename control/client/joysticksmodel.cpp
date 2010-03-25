#include "joysticksmodel.h"
#include "qjoystick.h"

#include <QListWidget>
#include <QList>
#include <QString>

JoystickItem::JoystickItem(QJoystick &joystick)
	: QStandardItem(joystick.path())
	, m_joystick(&joystick)
{
	QList<QStandardItem*> item;
	item.append(new QStandardItem("ROV"));
	appendColumn(item);
}

JoysticksModel::JoysticksModel(QObject *parent)
	: QStandardItemModel(parent)
{
	QList<QString> headerLabels;
	headerLabels.append("Path");
	headerLabels.append("ROV");
	setHorizontalHeaderLabels(headerLabels);
}

void JoysticksModel::addJoystick(QJoystick &joystick)
{
	appendRow(new JoystickItem(joystick));
}

#include "joysticksmodel.moc"

