#include "gamemaker.h"

#include <QVector>
#include <QWebSocket>

#include "awaleserver.h"

GameMaker::GameMaker(QObject *parent) :
	QObject(parent), m_waitingAccount(0), m_games()
{
}

int GameMaker::createGame(Account *account)
{
	if (m_waitingAccount) {
        Game *game = new Game(this);
		game->setPlayer1(m_waitingAccount);
		game->setPlayer2(account);
		m_games << game;

        m_waitingAccount = 0;
        game->start(2);
		game->sendStateOfTheWorld();

	} else {
		m_waitingAccount = account;
		account->client()->sendTextMessage("waiting");
        return -1;
	}
}

QVector<Game *> GameMaker::accountGames(Account *account)
{
	QVector<Game *> games;
	foreach(Game *game, m_games) {
		if (game->player1() == account || game->player2() == account) {
			games << game;
		}
	}
	return games;
}


