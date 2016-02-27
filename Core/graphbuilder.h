#ifndef GRAPHBUILDER_H
#define GRAPHBUILDER_H

#include <QObject>
#include <QElapsedTimer>

#include "awale.h"

class GraphBuilder : public QObject
{
	Q_OBJECT

public:
    enum Method {
        Random,
        Graph,
        Learning
    };

public:
    explicit GraphBuilder(Awale* awale, Method method, QObject *parent = 0);
    int selectBestHole();

	Awale *awale() const;
	void setAwale(Awale *awale);

signals:

public slots:

private:
	Awale* m_awale;
    Method m_method;
};

#endif // GRAPHBUILDER_H
