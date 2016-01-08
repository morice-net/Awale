#ifndef GRAPHBUILDER_H
#define GRAPHBUILDER_H

#include <QObject>
#include <QElapsedTimer>

#include "awale.h"

class GraphBuilder : public QObject
{
	Q_OBJECT
public:
	explicit GraphBuilder(QObject *parent = 0);

signals:

public slots:

private:
};

#endif // GRAPHBUILDER_H
