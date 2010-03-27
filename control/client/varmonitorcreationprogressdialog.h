#ifndef VAR_MONITOR_CREATION_PROGRESS_DIALOG
#define VAR_MONITOR_CREATION_PROGRESS_DIALOG

#include <QProgressDialog>
#include <QString>

class RovConnection;

class VarMonitorCreationProgressDialog
	: public QProgressDialog
{
	Q_OBJECT

	public:
		VarMonitorCreationProgressDialog(
			RovConnection &conn,
			const QString &var,
			QWidget *parent = 0);
		

};

#endif

