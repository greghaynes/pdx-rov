#ifndef VAR_MONITOR_BUILDER
#define VAR_MONITOR_BUILDER

#include <QObject>
#include <QList>
#include <QString>

class RovConnection;
class VarMonitor;

class VarMonitorBuilder
	: public QObject
{
	Q_OBJECT

	public:
		static VarMonitorBuilder &instance();

		void createVarMonitor(RovConnection &conn,
			const QString &var);

	Q_SIGNALS:
		void varMonitorCreated(VarMonitor *mon);

	protected:
		VarMonitorBuilder();

};

#endif

