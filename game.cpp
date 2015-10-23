#include "game.h"

Game::Game(QObject *parent) :
	QObject(parent), m_root(0), m_awale()
{
	m_awale.initialize();
	connect( &m_awale, SIGNAL(playerHalve1Changed()), this, SLOT(updateView()));
	connect( &m_awale, SIGNAL(playerHalve2Changed()), this, SLOT(updateView()));
	connect( &m_awale, SIGNAL(playerScore1Changed()), this, SLOT(updateView()));
	connect( &m_awale, SIGNAL(playerScore2Changed()), this, SLOT(updateView()));
	connect( &m_awale, SIGNAL(takenHoleChanged()), this, SLOT(updateView()));
	connect( &m_awale, SIGNAL(playerTurnChanged()), this, SLOT(updateView()));
}


void Game::updateView()
{
	if (! m_root) {
		return;
	}
	m_root->setProperty("playerScore1", m_awale.playerScore1());
	m_root->setProperty("playerScore2", m_awale.playerScore2());
	m_root->setProperty("takenHole", m_awale.takenHole());
	m_root->setProperty("playerHalve1", QVariant::fromValue(m_awale.playerHalve1()));
	m_root->setProperty("playerHalve2", QVariant::fromValue(m_awale.playerHalve2()));
	m_root->setProperty("playerTurn", QVariant::fromValue(m_awale.playerTurn()));
}

void Game::takeHole(int player, int holeNumber)
{
	m_awale.takeHole(player,holeNumber);
	m_awale.draw(player,holeNumber);
}

/* Getters and Setters */
QQuickItem *Game::root() const
{
	return m_root;
}

void Game::setRoot(QQuickItem *root)
{
	m_root = root;
}


