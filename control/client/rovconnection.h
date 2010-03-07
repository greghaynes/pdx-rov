#ifndef ROV_CONNECTION_H
#define ROV_CONNECTION_H

#include <QObject>
#include <QTcpSocket>

class RovConnection
	: public QTcpSocket
{
	Q_OBJECT

	public:
		RovConnection(QObject *parent = 0);

		bool setVar(const QString &name,
			const QString &value);

		/**
		 * @brief Ask the server to respond with var state
		 *
		 * This call asks the server to send var state, which
		 * will trigger var signal.  This may or may not happen
		 * depending on how nicely you ask.
		 */
		bool reqVar(const QString &name);

	private Q_SLOTS:
		void dataRecieved();

	Q_SIGNALS:
		void var(const QString &name,
			const QString &value);

};

#endif

