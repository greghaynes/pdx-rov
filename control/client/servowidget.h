#ifndef SERVO_WIDGET_H
#define SERVO_WIDGET_H

#include "varmonitor.h"

#include <QWidget>
#include <QString>
#include <QLabel>

class RovConnection;

class ServoWidget
	: public QWidget
	, public VarMonitor
{
	
	public:
		ServoWidget(const QString &name,
			const QString &var_name,
			RovConnection &conn,
			QWidget *parent = 0);

		~ServoWidget();

		int max() const;
		int min() const;
		int pos() const;
		void setPos(int val);
		void gotValue(const QString &value);

	private:
		int m_max;
		int m_min;
		int m_pos;
		QString m_str_pos;

		QLabel *posLabel;
		RovConnection *m_conn;

};

#endif

