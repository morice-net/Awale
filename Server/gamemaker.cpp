#include "gamemaker.h"

#include <QWebSocket>

#include "awaleserver.h"

GameMaker::GameMaker(QObject *parent) :
	QObject(parent), m_waitingAccount(0)
{
}

int GameMaker::createGame(Account *account, QWebSocket* client)
{
	if (m_waitingAccount) {
        Game *game = new Game(this);
		game->setPlayer1(m_waitingAccount);
		game->setPlayer2(account);
        m_games.insert(game->id(),game);

        m_waitingAccount = 0;
        game->start(2);

		game->player1()->client()->sendTextMessage(game->stateOfTheWorld());
		game->player2()->client()->sendTextMessage(game->stateOfTheWorld());

	} else {
		m_waitingAccount = account;
		client->sendTextMessage("waiting");
        return -1;
	}
}

Game *GameMaker::gameById(int gameId)
{
    return m_games.value(gameId,0);
}


