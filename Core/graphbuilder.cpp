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
	QVector<int> bestHoles;
	HoleEvaluator evaluator(m_awale, this);
	for (int i = 6; i < 12; ++i) {
		if (!m_awale->playables().at(i))
		{
			continue;
		}
		int holeValue = evaluator.evaluate(i);
		qDebug() << "Hole" << i << "evaluated in" << evaluator.elapsed() << "ms";
		if (holeValue > bestValue) {
			// Init the best value at the first playable hole
			bestValue = holeValue;
			bestHoles.clear();
			bestHoles << i;
		} else if (holeValue == bestValue) {
			bestHoles << i;
		}
	}

	// Choose a random value between the best already found
	int randHole = qrand() % bestHoles.size();
	return (bestHoles[randHole] - 6);
}

Awale *GraphBuilder::awale() const
{
	return m_awale;
}

void GraphBuilder::setAwale(Awale *awale)
{
	m_awale = awale;
}
