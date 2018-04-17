#ifndef SQLITESTORAGE_H
#define SQLITESTORAGE_H

#include "objectstorage.h"

#include <QSqlDatabase>

class Account;

class SQLiteStorage : public ObjectStorage
{
    Q_OBJECT
public:
    explicit SQLiteStorage(QObject * parent = 0);

    bool readDatabase();
    bool createObject(QString tableName, QVector<QString> columnNames, QVector<QString> columnValues);
    bool createTable(QString tableName, QVector<QString> columnNames, QVector<QString> columnTypes);
    QString stringFromType(QVariant::Type type) const;

public slots:
    void onAccountCreated(Account * account);

private:
    QSqlDatabase m_database;

};

#endif // SQLITESTORAGE_H
