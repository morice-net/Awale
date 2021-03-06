#include "xmltools.h"

// Qt
#include <QStringList>

XmlTools::XmlTools()
{

}

QString XmlTools::xmlFromValue(const QString &name, const QString &value)
{
	QString xml("<%1>%2</%1>");
	return xml.arg(name).arg(value);
}

QString XmlTools::xmlFromValue(const QString &name, int value)
{
	QString xml("<%1>%2</%1>");
	return xml.arg(name).arg(value);
}

QString XmlTools::xmlFromValue(const QString &name, const QVector<int> &values)
{
	QString xml("<%1>%2</%1>");
	QStringList value;
	foreach (int i, values) {
		value << QString::number(i);
	}

    return xml.arg(name).arg(value.join(","));
}

QString XmlTools::header()
{
    return QString("<?xml version='1.0' encoding='utf-8'?><State>");
}

QString XmlTools::footer()
{
    return QString("</State>");
}



