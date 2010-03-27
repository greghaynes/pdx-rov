#include "varmonitor.h"

VarMonitor::VarMonitor(const QString &var_name)
	: m_name(var_name)
{
}

VarMonitor::~VarMonitor()
{
}

const QString &VarMonitor::name() const
{
	return m_name;
}

