#include "gamemaker.h"

GameMaker::GameMaker(QObject *parent) :
	QObject(parent), m_waitingAccount(0)
{
}

void GameMaker::onLoggedIn(const QString &login)
{
	Account* newAccount = new Account(this);
	newAccount->setLogin(login);

	if (m_waitingAccount) {
		Game* game = new Game(this);
		game->setPlayer1(m_waitingAccount);
		game->setPlayer2(newAccount);
		game->start(2);

		m_games << game;
	} else {
		m_waitingAccount = newAccount;
	}
}


