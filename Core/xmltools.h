#ifndef XMLTOOLS_H
#define XMLTOOLS_H

#include <QString>
#include <QVector>

class XmlTools
{
public:
	XmlTools();

	QString xmlFromValue(const QString &name, const QString &value);
	QString xmlFromValue(const QString &name, int value);
	QString xmlFromValue(const QString &name, const QVector<int> &values);
    QString header();
    QString footer();
};

#endif // XMLTOOLS_H
