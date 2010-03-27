#ifndef VAR_MONITOR_BUILDER
#define VAR_MONITOR_BUILDER

#include <QObject>
#include <QList>
#include <QString>

class RovConnection;

class VarMonitorBuilder
	: public QObject
{
	Q_OBJECT

	public:
		static VarMonitorBuilder &instance();

		void createVarMonitor(RovConnection &conn,
			const QString &var);

		/* Returned widget will be added to connection automaticly,
		   Do not do this yourself. */
		virtual QWidget *buildVarMonitor(RovConnection &conn,
			const QString &var,
			const QString &type);

	protected:
		VarMonitorBuilder();

	private Q_SLOTS:
		void varTypeResponse(const QString &var,
			const QString &type);
		void connectionAdded(RovConnection &conn);

	private:
		QList<QString> build_wait_type;

};

#endif

