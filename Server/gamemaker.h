#ifndef WAITINGGAMES_H
#define WAITINGGAMES_H

#include "account.h"
#include "game.h"

#include <QObject>
#include <QMap>

class GameMaker : public QObject
{
	Q_OBJECT
public:
	explicit GameMaker(QObject *parent = 0);
    int onLoggedIn(const QString& login, QObject *communicator);
    Game *gameById(int gameId);

private:
	Account* m_waitingAccount;
    QMap<int,Game*> m_games;
};

#endif // WAITINGGAMES_H
