#ifndef GRAPHBUILDER_H
#define GRAPHBUILDER_H

#include <QObject>
#include <QElapsedTimer>

#include "awale.h"

class GraphBuilder : public QObject
{
	Q_OBJECT
public:
	explicit GraphBuilder(Awale* awale, QObject *parent = 0);
	int selectBestHole();

	Awale *awale() const;
	void setAwale(Awale *awale);

signals:

public slots:

private:
	Awale* m_awale;
};

#endif // GRAPHBUILDER_H
