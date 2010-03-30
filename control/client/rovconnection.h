#ifndef ROV_CONNECTION_H
#define ROV_CONNECTION_H

#include <QObject>
#include <QTcpSocket>
#include <QHash>
#include <QString>

class VarMonitor;

class RovConnection
	: public QTcpSocket
{
	Q_OBJECT

	public:
		RovConnection(QString label = QString(),
			QObject *parent = 0);
		~RovConnection();

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

		void addMonitor(VarMonitor &monitor);

		const QString &label() const;

		void removeMonitor(VarMonitor &monitor);

		void queryVarType(const QString &name);

	private Q_SLOTS:
		void dataRecieved();

	Q_SIGNALS:
		void var(const QString &name,
			const QString &value);
		void queryTypeResponse(const QString &name,
			const QString &value);

	private:
		QString m_label;
		QHash<QString, QList<VarMonitor*> > monitors;
		QList<VarMonitor*> monitor_list;

};

#endif

