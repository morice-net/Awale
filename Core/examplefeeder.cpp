#include "examplefeeder.h"

#include <QDebug>
#include <QString>
#include <QFile>

ExampleFeeder::ExampleFeeder(QObject *parent) : QObject(parent), m_recordFile("AwaleTrain.csv")
{
    connect(this, SIGNAL(record(const QString &)), SLOT(onRecord(const QString &)));
}

void ExampleFeeder::addExample(const QVector<Awale> &awales, const QVector<int> &plays, bool reverse)
{
    for (int i = 0; i < plays.size(); ++i)
    {
        QStringList row;
        if (! reverse) {
            foreach (int hole, awales.at(i).playerHalve1()) {
                row << QString::number(hole);
            }
        }
        foreach (int hole, awales.at(i).playerHalve2()) {
            row << QString::number(hole);
        }
        if (reverse) {
            foreach (int hole, awales.at(i).playerHalve1()) {
                row << QString::number(hole);
            }
        }
        row << QString::number(plays.at(i));
        emit record(row.join(" ").append(QString("\n")));
        i++;
    }
}

void ExampleFeeder::onRecord(const QString &row)
{
    if (!m_recordFile.isOpen()) {
        m_recordFile.open(QIODevice::WriteOnly);
    }
    m_recordFile.write(row.toUtf8());
}






