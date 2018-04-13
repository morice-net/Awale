#include "sqlitestorage.h"

#include <QSqlDatabase>
#include <QSqlQuery>

#include "account.h"

SQLiteStorage::SQLiteStorage(QObject *parent) : ObjectStorage(parent)
{
    QString path = "AwaleDatabase";
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(path);
    db.open();

}

bool SQLiteStorage::readDatabase()
{
    return true;
}

bool SQLiteStorage::createObject(QString tableName, QVector<QString> columnNames, QVector<QString> columnValues)
{
    QString queryCommand;
    queryCommand += "insert into " + tableName + " ( ";
    for(int i = 0; i < columnNames.size(); i++) {
        queryCommand += columnNames[i];
        if (i == (columnNames.size() - 1))
            queryCommand += " ) ";
        else
            queryCommand += ", ";
    }
    queryCommand += "VALUES (";
    for(int i = 0; i < columnValues.size(); i++) {
        queryCommand += columnValues[i] ;
        if (i == (columnValues.size() - 1))
            queryCommand += " );";
        else
            queryCommand += ", ";
    }

    QSqlQuery query;
    return query.exec(queryCommand);
}

bool SQLiteStorage::createTable(QString tableName, QVector<QString> columnNames, QVector<QString> columnTypes)
{
    QString queryCommand;
    queryCommand += "create table " + tableName + " ( ";
    for(int i = 0; i < columnNames.size(); i++) {
        queryCommand += columnNames[i] + " " + columnTypes[i];
        if (i == (columnNames.size() - 1))
            queryCommand += " );";
        else
            queryCommand += ", ";
    }

    QSqlQuery query;
    return query.exec(queryCommand);
}

QString SQLiteStorage::stringFromType(QVariant::Type type) const
{
    if (type == QVariant::Int)
        return "INTEGER";
    else if (type == QVariant::String)
        return "TEXT";
    else
        return "TEXT";
}

void SQLiteStorage::onAccountCreated(Account *account)
{
    insertObject(account);
}
