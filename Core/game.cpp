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
	m_root->setProperty("playerHalve1", QVariant::fromValue(m_awales.last().playerHalve1().toList()));
	m_root->setProperty("playerHalve2", QVariant::fromValue(m_awales.last().playerHalve2().toList()));
	m_root->setProperty("playerTurn", QVariant::fromValue(m_awales.last().playerTurn()));
	m_root->setProperty("playable", QVariant::fromValue(m_awales.last().playables().toList()));
}

void Game::gameDone(Awale::Winner winner)
{
	int winnerProperty;
	switch (winner) {
	case Awale::Player1:
		winnerProperty = 1;
		break;
	case Awale::Player2:
		winnerProperty = 2;
		break;
	case Awale::Draw:
		winnerProperty = 0;
		break;
	case Awale::NoWinner:
		// Intended fold down
	default:
		winnerProperty = -1;
		break;
	}
	m_root->setProperty("winner", winnerProperty);
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
	gameDone(Awale::NoWinner);
}

void Game::onTakeHole(int player, int holeNumber)
{
	if (m_awales.isEmpty()) {
		return;
	}

	Awale newTurn;
	newTurn = m_awales.last();
	newTurn.takeHole(player,holeNumber);
	Awale::Winner isThereAWinner = newTurn.draw(player,holeNumber);
	m_awales.append(newTurn);

	if (isThereAWinner != Awale::NoWinner) {
		updateView();
		gameDone(isThereAWinner);
	} else {
		newTurn.computePlayable();
		updateView();
	}
}

void Game::onRevert()
{
	if (m_awales.isEmpty()) {
		return;
	}
	m_awales.removeLast();
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


