#ifndef CONNECTION_MANAGER_H
#define CONNECTION_MANAGER_H

#include <QObject>
#include <QDialog>
#include <QList>
#include <QAbstractSocket>

namespace Ui
{
	class CreateConnectionWidget;
};

class RovConnection;

class CreateConnectionDialog
	: public QDialog
{
	Q_OBJECT

	public:
		CreateConnectionDialog(QWidget *parent = 0);

		QString label();
		QString hostname();
		QString port();

	private:
		Ui::CreateConnectionWidget *ui;

};

class ConnectionManager
	: public QObject
{
	Q_OBJECT

	public:
		static ConnectionManager *instance();

		QList<RovConnection*> &connections();

	Q_SIGNALS:
		void connectionAdded(RovConnection &connection);

	public Q_SLOTS:
		void createConnection();

	private Q_SLOTS:
		void connectionError(QAbstractSocket::SocketError error);

	private:
		ConnectionManager();

		QList<RovConnection*> m_connections;

};

#endif

