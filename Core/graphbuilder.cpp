#include "graphbuilder.h"

// Qt
#include <QDebug>

// Local
#include "holeevaluator.h"


GraphBuilder::GraphBuilder(Awale* awale, QObject *parent) :
	QObject(parent), m_awale(awale)
{
}

/*!
 * \brief GraphBuilder::selectBestHole evaluates all the possible holes
 * \return a random hole between the best playable holes
 */
int GraphBuilder::selectBestHole()
{
	int bestValue = -1;
	int bestHole = -1;
	HoleEvaluator evaluator(m_awale, this);
	for (int i = 6; i < 12; ++i) {
		if (!m_awale->playables().at(i))
		{
			continue;
		}
		int holeValue = evaluator.evaluate(i);
		qDebug() << "Hole" << i << "evaluated in" << evaluator.elapsed() << "ms";
		if (holeValue == bestValue && bestHole != -1) {
			bestValue = holeValue;
			bestHole = i;
		} else if (holeValue >= bestValue) {
			if (qrand() % 2 == 1) {
				bestValue = holeValue;
				bestHole = i;
			}
		}
	}

	return (bestHole - 6);
}

Awale *GraphBuilder::awale() const
{
	return m_awale;
}

void GraphBuilder::setAwale(Awale *awale)
{
	m_awale = awale;
}
