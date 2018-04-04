#include "gamemaker.h"

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
		m_games.insert(game->id(),game);

        m_waitingAccount = 0;
        game->start(2);
		game->sendStateOfTheWorld();

	} else {
		m_waitingAccount = account;
		account->client()->sendTextMessage("waiting");
        return -1;
	}
}

void GameMaker::launchGame(Account *account)
{
	Game *game = new Game(this);
	game->setPlayer1(account);
	m_games.insert(game->id(),game);

	m_waitingAccount = 0;
	game->start(1);
	game->sendStateOfTheWorld();
}

void GameMaker::abortGame(int gameId, Account *account)
{
	Game *game = m_games.value(gameId);
	if (game == NULL) {
		return;
	}
	game->abort(account);
	game->sendStateOfTheWorld();
}

void GameMaker::takeHole(int id, Account *account, int hole)
{
    qDebug() << "Id" << id << "Account" << account->login() << "HoleNumber" << hole;
	Game *game = m_games.value(id);
	if (game == NULL) {
		return;
	}

    game->takeHole(account, hole);
}

QVector<Game *> GameMaker::accountGames(Account *account)
{
	QVector<Game *> games;
	foreach(Game *game, m_games.values()) {
		if (game->player1() == account || game->player2() == account) {
			games << game;
		}
	}
	return games;
}


