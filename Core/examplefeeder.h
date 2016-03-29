#ifndef EXAMPLEFEEDER_H
#define EXAMPLEFEEDER_H

#include <QObject>
#include <QFile>

#include "awale.h"


class ExampleFeeder : public QObject
{
    Q_OBJECT
public:
    explicit ExampleFeeder(QObject *parent = 0);

    void addExample(const QVector<Awale>& awales, const QVector<int> &plays);

signals:
    void record(const QString& row);

public slots:
    void onRecord(const QString& row);

private:
    QFile m_recordFile;
};

#endif // EXAMPLEFEEDER_H
