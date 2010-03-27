#ifndef VAR_MONITOR_BUILDER
#define VAR_MONITOR_BUILDER

#include <QObject>
#include <QList>
#include <QString>

class RovConnection;

class VarMonitorBuilder
	: public QObject
{

	public:
		static VarMonitorBuilder &instance();

		void createVarMonitor(RovConnection &conn,
			const QString &var);

	protected:
		VarMonitorBuilder();

};

#endif

