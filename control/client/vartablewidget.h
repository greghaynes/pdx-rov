#ifndef VAR_TABLE_WIDGET_H
#define VAR_TABLE_WIDGET_H

#include <QTableWidget>

class VarTableWidget
	: public QTableWidget
{

	public:
		VarTableWidget(QWidget *parent = 0);

	private:
		void setVar(const QString &name,
			const QString &value);

};

#endif

