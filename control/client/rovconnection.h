#ifndef ROV_CONNECTION_H
#define ROV_CONNECTION_H

#include <QObject>
#include <QTcpSocket>
#include <QString>
#include <QVariantMap>
#include <qjson/parser.h>
#include <qjson/serializer.h>

class VarMonitor;

class RovConnection
	: public QTcpSocket
{
	Q_OBJECT

	public:
		RovConnection(QString label = QString(),
			QObject *parent = 0);
		~RovConnection();

		void sendCommand(const QString &module,
			const QString &command,
			QVariantMap &arguments);

		const QString &label() const;

	Q_SIGNALS:
		void receivedCommand(const QString &module,
			const QString &command,
			QVariantMap &arguments);

	private Q_SLOTS:
		void dataReceived();

	private:
		QString m_label;

		QJson::Parser json_parser;
		QJson::Serializer json_serializer;

};

#endif

