// Self
#include "game.h"

// Qt
#include <QTimer>
#include <QWebSocket>
#include <QMetaProperty>
#include <QDebug>

// Awale
#include "graphbuilder.h"
#include "xmltools.h"

static int gameNumber;
Game::Game(QObject *parent) :
	QObject(parent),
	m_awales(),
	m_plays(),
	m_mode(Versus),
	m_isThereAWinner(Awale::NoWinner),
	m_id(gameNumber++),
	m_player1(NULL),
	m_player2(NULL)
{
	connect(this, &Game::gameDone, &Game::onGameDone);
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

	if (m_mode == Learning) {
		playRandom();
	}
}

void Game::abort(Account *account)
{
	if (account == m_player1) {
		m_isThereAWinner = Awale::Player2;
	} else {
		m_isThereAWinner = Awale::Player1;
	}
	emit gameDone();
}

void Game::sendStateOfTheWorld()
{
    XmlTools tool;
	const QString& state = stateOfTheWorld();
	// Player1 cannot be NULL because game would not exists
	QWebSocket* socket1 = m_player1->client();
	if (socket1 != NULL) {
        socket1->sendTextMessage(tool.header() + state + tool.footer());
	}
	// If the player plays alone against the AI
	if (m_player2 == NULL) {
		return;
	}
	QWebSocket* socket2 = m_player2->client();
	if (socket2 != NULL) {
        socket2->sendTextMessage(tool.header() + state + tool.footer());
	}
}

void Game::takeHole(Account *account, int holeNumber)
{
	int player = 0;
	if (account == m_player1) {
		player = 1;
	} else if (account == m_player2) {
		player = 2;
	}
    takePlayerHole(player, holeNumber);
}

void Game::takePlayerHole(int player, int holeNumber)
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
		emit gameDone();
	} else if (newTurn->playerTurn() == 2 && m_mode == Solo) {
		sendStateOfTheWorld();
        QTimer::singleShot( 3000, this, SLOT(onCPUTakeHole()) );
	}
	sendStateOfTheWorld();
}

void Game::onCPUTakeHole()
{
	if (m_awales.isEmpty()) {
		return;
	}

	GraphBuilder solution(m_awales.last(), GraphBuilder::Random, this);
    takePlayerHole(m_awales.last()->playerTurn(),solution.selectBestHole());
}

void Game::onRevert()
{
	if (m_awales.isEmpty()) {
		return;
	}
	m_awales.remove(m_awales.size()-1);
}

void Game::onGameDone()
{
	// We first close the game
	if (m_player1->client() != NULL) {
		m_player1->client()->sendTextMessage(QString("gameDone|%1").arg(m_id));
	}

	// No elo against the computer
	if (m_player2 == NULL) {
		deleteLater();
		return;
	}

	if (m_player2->client() != NULL) {
		m_player2->client()->sendTextMessage(QString("gameDone|%1").arg(m_id));
	}

	// We compute the elo of each player
	if (m_isThereAWinner == Awale::Player1) {
		m_player1->addGameResult(true, m_player2->elo());
		m_player2->addGameResult(false, m_player1->elo());
	} else {
		m_player1->addGameResult(false, m_player2->elo());
		m_player2->addGameResult(true, m_player1->elo());
	}

	deleteLater();
}
int Game::id() const
{
	return m_id;
}

void Game::setId(int id)
{
	m_id = id;
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

QString Game::stateOfTheWorld() const
{
	if (m_awales.isEmpty()) {
		QString err("Error");
		qDebug() << err;
		return err;
	}

	QString result;
	result.append(m_player1->xmlState());
    if (m_player2 != NULL) {
        result.append(m_player2->xmlState());
    }
    result.append(QString("<Game id='%1'>").arg(m_id));
	result.append(m_awales.last()->xmlState());
    result.append(QString("</Game>"));
	return result;
}


