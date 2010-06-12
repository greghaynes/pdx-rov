#ifndef CONNECTINGDIALOG_H
#define CONNECTINGDIALOG_H

#include <QProgressDialog>
#include <QTcpSocket>

class ConnectingDialog
	: public QProgressDialog
{
	Q_OBJECT

	public:

		ConnectingDialog(QWidget *parent = 0);

		bool waitForConnectionOn(QTcpSocket &connection);


	private Q_SLOTS:
		void connected();
		void error(QAbstractSocket::SocketError socketError);

};

#endif // CONNECTINGDIALOG_H
