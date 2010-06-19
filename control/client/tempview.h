#ifndef TEMP_VIEW_H
#define TEMP_VIEW_H

#include <QWidget>
#include <QString>
#include <QVariantMap>

class QTimer;
class QLabel;

class RovConnection;

class TempView
	: public QWidget
{

	Q_OBJECT

	public:
		TempView(QWidget *parent = 0);

		void setConnection(RovConnection &conn);
		void setProbeName(const QString);

	private Q_SLOTS:
		void req_update_temp();
		void handle_command(const QString &module,
			const QString &command_name,
			QVariantMap &arguments);

	private:
		RovConnection *m_conn;
		QTimer *m_timer;
		QString m_probeName;
		QLabel *tempValLabel;

};

#endif

