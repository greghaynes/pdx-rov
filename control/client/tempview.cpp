#include "tempview.h"
#include "rovconnection.h"

#include <QTimer>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QVariantMap>

TempView::TempView(QWidget *parent)
	: QWidget(parent)
	, m_conn(0)
	, m_timer(new QTimer(this))
{
	tempValLabel = new QLabel("0");

	QHBoxLayout *mainHLayout = new QHBoxLayout();
	mainHLayout->addWidget(tempValLabel);
	mainHLayout->addWidget(new QLabel(" deg C"));

	QVBoxLayout *mainVLayout = new QVBoxLayout();
	mainVLayout->addWidget(new QLabel("Arm Temperature"));
	mainVLayout->addLayout(mainHLayout);

	setLayout(mainVLayout);
}

void TempView::setConnection(RovConnection &conn)
{
	if(&conn == m_conn)
		return;

	if(m_conn)
		delete m_conn;

	m_conn = &conn;
}

void TempView::req_update_temp()
{
	if(!m_conn)
		return;

	QVariantMap args;
	args.insert("probe", "Arm");

	m_conn->sendCommand("temperature", "query", args);
}

void TempView::handle_command(const QString &module,
	const QString &command_name,
	QVariantMap &arguments)
{
	if(module == "temperature"
		&& command_name == "query"
		&& arguments["probe"].toString() == "Arm")
	{
		qDebug() << "Got temp response";
	}
}

#include "tempview.moc"

