#ifndef CONNECTION_MANAGER_H
#define CONNECTION_MANAGER_H

#include <QObject>
#include <QDialog>
#include <QList>

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
		ConnectionManager();

		QList<RovConnection*> &connections();

	Q_SIGNALS:
		void connectionAdded(RovConnection &connection);

	public Q_SLOTS:
		void createConnection();

	private:
		QList<RovConnection*> m_connections;

};

#endif

