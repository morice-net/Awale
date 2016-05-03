#ifndef WAITINGGAMES_H
#define WAITINGGAMES_H

#include <QObject>
#include <QMap>

#include "account.h"
#include "game.h"

class GameMaker : public QObject
{
	Q_OBJECT
public:
	explicit GameMaker(QObject *parent = 0);
	int createGame(Account* account);
	QVector<Game *> accountGames(Account* account);
	void takeHole(int id, Account* account, int hole);

private:
	Account* m_waitingAccount;
	QMap<int,Game*> m_games;
};

#endif // WAITINGGAMES_H
