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
		emit newGame(game, m_waitingAccount, newAccount);
	}
}


