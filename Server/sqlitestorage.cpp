#include "sqlitestorage.h"

#include <QCoreApplication>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QDebug>

#include "account.h"

SQLiteStorage::SQLiteStorage(QObject *parent) : ObjectStorage(parent)
{
    QString path = "./AwaleDatabase.db";
    m_database = QSqlDatabase::addDatabase("QSQLITE");
    m_database.setDatabaseName(path);
    if (! m_database.open()) {
        qDebug() << m_database.lastError().text();

        qDebug() << QCoreApplication::libraryPaths();
        QCoreApplication::exit(-1);
    }

    readDatabase();
}

bool SQLiteStorage::readDatabase()
{
    qDebug() << "Reading database to reload most of things.";
    QSqlQuery query;
    query.exec("SELECT name FROM sqlite_master WHERE type='table'");
    int idName = query.record().indexOf("name");
    while (query.next())
    {
       QString tablename = query.value(idName).toString();
       qDebug() << tablename;
       QSqlQuery select;
       select.exec("SELECT * FROM " + tablename);
       while (select.next())
       {
           for (int i = 0; i < select.record().count(); i++)
                qDebug() << "\t" << select.value(i).toString();
       }
    }

    return true;
}

bool SQLiteStorage::createObject(QString tableName, QVector<QString> columnNames, QVector<QString> columnValues)
{
    QString queryCommand;
    queryCommand += "INSERT INTO " + tableName + " ( ";
    for(int i = 0; i < columnNames.size(); i++) {
        queryCommand += columnNames[i];
        if (i == (columnNames.size() - 1))
            queryCommand += " ) ";
        else
            queryCommand += ", ";
    }
    queryCommand += "VALUES (";
    for(int i = 0; i < columnValues.size(); i++) {
        queryCommand += "\"" + columnValues[i] + "\"";
        if (i == (columnValues.size() - 1))
            queryCommand += " );";
        else
            queryCommand += ", ";
    }

    QSqlQuery query;
    query.exec(queryCommand);
    qDebug() << queryCommand;
    qDebug() << query.lastError().text();
    return true;
}

bool SQLiteStorage::createTable(QString tableName, QVector<QString> columnNames, QVector<QString> columnTypes)
{
    QString queryCommand;
    queryCommand += "CREATE TABLE IF NOT EXISTS " + tableName + " ( ";
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
