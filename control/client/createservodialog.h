#ifndef CREATE_SERVO_DIALOG
#define CREATE_SERVO_DIALOG

#include <QDialog>

namespace Ui
{
	class CreateServoWidget;
};

class RovConnection;
class ConnectionManager;

class CreateServoDialog
	: public QDialog
{
	Q_OBJECT

	public:
		CreateServoDialog(ConnectionManager &conn_manager,
			QWidget *parent = 0);

		QString name();

	private Q_SLOTS:
		void connectionAdded(RovConnection &conn);

	private:
		Ui::CreateServoWidget *ui;

};

#endif

