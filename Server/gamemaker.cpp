#include "gamemaker.h"

#include "awaleserver.h"

GameMaker::GameMaker(QObject *parent) :
	QObject(parent), m_waitingAccount(0)
{
}

int GameMaker::onLoggedIn(const QString &login, QObject* communicator)
{
    Account *newAccount = new Account(communicator);
    newAccount->setLogin(login);

	if (m_waitingAccount) {
        Game *game = new Game(this);
		game->setPlayer1(m_waitingAccount);
		game->setPlayer2(newAccount);
        m_games.insert(game->id(),game);

        m_waitingAccount = 0;
        game->start(2);
        return game->id();

	} else {
		m_waitingAccount = newAccount;
        return -1;
    }
}

Game *GameMaker::gameById(int gameId)
{
    return m_games.value(gameId,0);
}


