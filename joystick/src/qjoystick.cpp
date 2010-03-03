#include "qjoystick.h"

QJoystick::QJoystick(const QUrl &path,
	QObject *parent = 0)
	: QObject(parent)
	, filesysWatcher(new QFileSystemWatcher(this))
{
	connect(filesysWatcher, SIGNAL(fileChanged(const QString&)),
		this, SLOT(onChanged(const QString&)));
	filesysWatcher->addPath(path);
}

QString QJoystick::name()
{
}

QString QJoystick::device()
{
}

int QJoystick::numButtons()
{
}

int QJoystick::numAxes()
{
}

void QJoystick::onChanged(const QString &path)
{
	qDebug() << "Something changed.";
}

