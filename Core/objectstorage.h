#ifndef OBJECTSTORAGE_H
#define OBJECTSTORAGE_H

#include <QObject>
#include <QVector>
#include <QVariant>

class ObjectStorage : public QObject
{
	Q_OBJECT

public:
	explicit ObjectStorage(QObject *parent = 0);

	virtual bool readDatabase() = 0;
	virtual bool createObject(QString tableName, QVector<QString> columnNames, QVector<QString> columnValues) = 0;
	virtual bool createTable(QString tableName, QVector<QString> columnNames, QVector<QString> columnTypes) = 0;
	virtual QString getStringFromType(QVariant::Type type) = 0;

	bool createTableFromObject(QObject* dataRow);
	bool insertObject(QObject* dataRow);

	QVector<QObject *> dataTableObjects(const QString& tableName) const;
	QVector<QObject *> dataObjects() const;
	QVector<QString> tableNames() const;

protected:
	/**
	 * List of tables
	 * Table name is the object name of the QObject
	 * Columns are Q_PROPERTIES
	 * Rows are children objects (one object is one row)
	 */
	QVector<QObject*> m_dataObjects;
	QVector<QString> m_tableNames;

};

#endif // OBJECTSTORAGE_H
