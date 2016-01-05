#include "game.h"

Game::Game(QObject *parent) :
	QObject(parent), m_root(0), m_awales(), m_mode(Versus)
{
}

void Game::updateView()
{
	if (! m_root) {
		return;
	}

	if (m_awales.isEmpty()) {
		return;
	}

	m_root->setProperty("playerScore1", m_awales.last().playerScore1());
	m_root->setProperty("playerScore2", m_awales.last().playerScore2());
	m_root->setProperty("takenHole", m_awales.last().takenHole());
	m_root->setProperty("playerHalve1", QVariant::fromValue(m_awales.last().playerHalve1()));
	m_root->setProperty("playerHalve2", QVariant::fromValue(m_awales.last().playerHalve2()));
	m_root->setProperty("playerTurn", QVariant::fromValue(m_awales.last().playerTurn()));
	m_root->setProperty("winner", QVariant::fromValue(-1));
}

void Game::gameDone(int winner)
{
	m_root->setProperty("winner", winner);
}

void Game::onStart(int mode)
{
	// Record the type of user choosen game
	if (mode == 1) {
		m_mode = Solo;
	} else {
		m_mode = Versus;
	}

	// Up for a new round
	m_awales.clear();

	// Initialize the begin of the game
	Awale awale;
	awale.initialize();
	m_awales.append(awale);
	updateView();
}

void Game::takeHole(int player, int holeNumber)
{
	if (m_awales.isEmpty()) {
		return;
	}

	Awale newTurn;
	newTurn = m_awales.last();
	newTurn.takeHole(player,holeNumber);
	newTurn.draw(player,holeNumber);
	m_awales.append(newTurn);
	updateView();
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


