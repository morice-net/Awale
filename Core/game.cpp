// Self
#include "game.h"

// Qt
#include <QTimer>
#include <QDebug>

// Awale
#include "graphbuilder.h"

Game::Game(QObject *parent) :
    QObject(parent), m_root(0), m_awales(), m_plays(), m_mode(Versus), m_feeder(this), m_isThereAWinner(Awale::NoWinner)
{
}

void Game::updateView()
{
    if (m_mode == Learning) {
        return;
    }

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
	if (m_mode == Solo) {
		m_root->setProperty("mode",1);
	} else if (m_mode == Versus) {
		m_root->setProperty("mode",2);
	}
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
    } else if (mode == 2) {
        m_mode = Versus;
    } else {
        m_mode = Learning;
	}

	// Up for a new round
	m_awales.clear();
    m_plays.clear();
    m_isThereAWinner = Awale::NoWinner;

	// Initialize the begin of the game
	Awale awale;
	awale.initialize();
	m_awales.append(awale);
	updateView();
	gameDone(Awale::NoWinner);

    if (m_mode == Learning) {
        playRandom();
    }
}

void Game::onTakeHole(int player, int holeNumber)
{
	if (m_awales.isEmpty()) {
		return;
	}
    if (holeNumber == -1) {
        if (player == 1) {
            m_isThereAWinner = Awale::Player2;
        } else {
            m_isThereAWinner = Awale::Player1;
        }
        return;
    }

	Awale newTurn;
	newTurn = m_awales.last();
	newTurn.takeHole(player,holeNumber);
    m_isThereAWinner = newTurn.draw(player,holeNumber);
    if (m_isThereAWinner == Awale::NoWinner) {
		newTurn.computePlayable();
	}
	m_awales.append(newTurn);
    m_plays.append(holeNumber);

	updateView();
    if (m_isThereAWinner != Awale::NoWinner) {
        gameDone(m_isThereAWinner);
	} else if (newTurn.playerTurn() == 2 && m_mode == Solo) {
		QTimer::singleShot( 3500, Qt::PreciseTimer, this, SLOT(onCPUTakeHole()) );
	}
}

void Game::onCPUTakeHole()
{
	if (m_awales.isEmpty()) {
		return;
	}

    GraphBuilder solution(&(m_awales.last()), GraphBuilder::Random, this);
    onTakeHole(m_awales.last().playerTurn(),solution.selectBestHole());
}

void Game::onRevert()
{
	if (m_awales.isEmpty()) {
		return;
	}
	m_awales.removeLast();
	updateView();
}

void Game::playRandom()
{
    while(m_isThereAWinner == Awale::NoWinner) {
        onCPUTakeHole();
    }
    if (m_isThereAWinner == Awale::Player1) {
        m_feeder.addExample(m_awales,m_plays,false);
    } else if (m_isThereAWinner == Awale::Player2) {
        m_feeder.addExample(m_awales,m_plays,true);
    }
    QString winnerString = "draw";
    if (m_isThereAWinner == Awale::Player1) {
        winnerString = "player 1";
    } else if (m_isThereAWinner == Awale::Player2) {
        winnerString = "player 2";
    }
    qDebug() << "Winner is" << winnerString;
    onStart(3);
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


