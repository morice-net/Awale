#ifndef HOLEEVALUATOR_H
#define HOLEEVALUATOR_H

#include <QObject>
#include <QElapsedTimer>

#include "awale.h"

class HoleEvaluator : public QObject
{
	Q_OBJECT
public:
	explicit HoleEvaluator(Awale* awale, QObject* parent = 0);
	int evaluate(int holeNumber);
	qint64 elapsed();

signals:

public slots:

private:
	Awale* m_awale;
	int m_deep;
	int m_gain;
	int m_loss;
	QElapsedTimer m_elapsed;
};

#endif // HOLEEVALUATOR_H
