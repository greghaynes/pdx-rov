#ifndef CREATE_VAR_MONITOR_DIALOG
#define CREATE_VAR_MONITOR_DIALOG

#include <QDialog>

namespace Ui
{
	class CreateVarMonitorWidget;
};

class RovConnection;
class ConnectionManager;

class CreateVarMonitorDialog
	: public QDialog
{
	Q_OBJECT

	public:
		CreateVarMonitorDialog(ConnectionManager &conn_manager,
			QWidget *parent = 0);

		QString name();
		RovConnection &connection();

	private Q_SLOTS:
		void connectionAdded(RovConnection &conn);

	private:
		Ui::CreateVarMonitorWidget *ui;
		ConnectionManager *m_conn_manager;

};

#endif

