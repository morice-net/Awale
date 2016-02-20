#include "holeevaluator.h"

HoleEvaluator::HoleEvaluator(Awale* awale, QObject* parent) :
	QObject(parent), m_initialAwale(awale), m_awale(), m_deep(0), m_gain(0), m_loss(0)
{
}

int HoleEvaluator::evaluate(int holeNumber)
{
	m_elapsed.restart();
	QVector<int> firstAwale(12);
	firstAwale << m_initialAwale->playerHalve1() << m_initialAwale->playerHalve2();

	return 1;
}

qint64 HoleEvaluator::elapsed()
{
	return m_elapsed.elapsed();
}
