#include "game.h"

Game::Game(QObject *parent) :
	QObject(parent), m_awale()
{
	m_awale.initialize();
}
