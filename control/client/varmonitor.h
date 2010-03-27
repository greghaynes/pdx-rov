#ifndef VAR_SERVER_MONITOR
#define VAR_SERVER_MONITOR

#include <QString>

class VarMonitor
{

	public:
		VarMonitor(const QString &var_name);
		virtual ~VarMonitor();

		const QString &name() const;
		virtual void gotValue(const QString &value) = 0;

	private:
		QString m_name;

};

#endif

