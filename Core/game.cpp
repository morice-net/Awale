// Self
#include "game.h"

// Qt
#include <QTimer>
#include <QMetaProperty>
#include <QDebug>

// Awale
#include "graphbuilder.h"

static int gameNumber;
Game::Game(QObject *parent) :
	QObject(parent),
	m_awales(),
	m_plays(),
	m_mode(Versus),
	m_isThereAWinner(Awale::NoWinner),
	m_id(gameNumber++),
	m_player1(0),
	m_player2(0)
{
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
}

void Game::start(int mode)
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
	Awale *awale = new Awale();
	awale->initialize();
    m_awales.append(awale);
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

	Awale *newTurn = m_awales.last();
	newTurn->takeHole(player,holeNumber);
	m_isThereAWinner = newTurn->draw(player,holeNumber);
    if (m_isThereAWinner == Awale::NoWinner) {
		newTurn->computePlayable();
	}
	m_awales.append(newTurn);
    m_plays.append(holeNumber);

    if (m_isThereAWinner != Awale::NoWinner) {
        gameDone(m_isThereAWinner);
	} else if (newTurn->playerTurn() == 2 && m_mode == Solo) {
        QTimer::singleShot( 500, this, SLOT(onCPUTakeHole()) );
	}
}

void Game::onCPUTakeHole()
{
	if (m_awales.isEmpty()) {
		return;
	}

	GraphBuilder solution(m_awales.last(), GraphBuilder::Random, this);
	onTakeHole(m_awales.last()->playerTurn(),solution.selectBestHole());
}

void Game::onRevert()
{
	if (m_awales.isEmpty()) {
		return;
	}
    m_awales.remove(m_awales.size()-1);
}
Account *Game::player2() const
{
	return m_player2;
}

void Game::setPlayer2(Account *player2)
{
	m_player2 = player2;
}

Account *Game::player1() const
{
	return m_player1;
}

void Game::setPlayer1(Account *player1)
{
	m_player1 = player1;
}


void Game::playRandom()
{
	while(m_isThereAWinner == Awale::NoWinner) {
		onCPUTakeHole();
	}
	if (m_isThereAWinner == Awale::Player1) {
        //m_feeder.addExample(m_awales,m_plays,false);
    } else if (m_isThereAWinner == Awale::Player2) {
        //m_feeder.addExample(m_awales,m_plays,true);
    }
    QString winnerString = "draw";
    if (m_isThereAWinner == Awale::Player1) {
		winnerString = m_player1->login();
    } else if (m_isThereAWinner == Awale::Player2) {
		winnerString = m_player2->login();
    }
    qDebug() << "Winner is" << winnerString;
	start(3);
}

QString Game::stateOfTheWorld()
{
	if (m_awales.isEmpty()) {
		qDebug() << "Error";
		return "Error";
	}

	QString result;
	result.append(QString("<Game>%1</Game>").arg(m_id));
	result.append(m_player1->xmlState());
	result.append(m_player2->xmlState());
	result.append(m_awales.last()->xmlState());
	qDebug() << result;
	return result;
}


