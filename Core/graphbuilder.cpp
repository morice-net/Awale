#include "graphbuilder.h"

// Qt
#include <QDebug>

// Local
#include "holeevaluator.h"


GraphBuilder::GraphBuilder(Awale* awale, Method method, QObject *parent) :
    QObject(parent), m_awale(awale), m_method(method)
{
}

/*!
 * \brief GraphBuilder::selectBestHole evaluates all the possible holes
 * \return a random hole between the best playable holes
 */
int GraphBuilder::selectBestHole()
{
	int bestValue = -1;
    int playerTurn = m_awale->playerTurn();
	QVector<int> bestHoles;
	HoleEvaluator evaluator(m_awale, this);
    int firstHole = (playerTurn - 1) * 6;
    for (int i = firstHole; i < firstHole + 6; ++i) {
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

    if (bestHoles.isEmpty()) {
        return -1;
    }
	// Choose a random value between the best already found
	int randHole = qrand() % bestHoles.size();
    return (bestHoles[randHole] - firstHole);
}

Awale *GraphBuilder::awale() const
{
	return m_awale;
}

void GraphBuilder::setAwale(Awale *awale)
{
	m_awale = awale;
}
