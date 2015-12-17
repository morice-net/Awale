#include "game.h"

Game::Game(QObject *parent) :
	QObject(parent), m_root(0), m_awale(), m_mode(Versus)
{
	m_awale.initialize();
	connect( &m_awale, &Awale::playerHalveChanged, this, &Game::updateView);
	connect( &m_awale, &Awale::playerScoreChanged, this, &Game::updateView);
    connect( &m_awale, &Awale::takenHoleChanged, this, &Game::updateView);
    connect( &m_awale, &Awale::playerTurnChanged, this, &Game::updateView);
	connect( &m_awale, &Awale::awaleDone, this, &Game::gameDone);
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
	m_root->setProperty("winner", QVariant::fromValue(-1));
}

void Game::gameDone(int winner)
{
	m_root->setProperty("winner", winner);
}

void Game::onStart(int mode)
{
	if (mode == 1) {
		m_mode = Solo;
	} else {
		m_mode = Versus;
	}
	updateView();
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


