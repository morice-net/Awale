#ifndef WAITINGGAMES_H
#define WAITINGGAMES_H

#include "account.h"
#include "game.h"

#include <QObject>

class GameMaker : public QObject
{
	Q_OBJECT
public:
	explicit GameMaker(QObject *parent = 0);

signals:
	void newGame(Game* game, Account* player1, Account* player2);

public slots:
	void onLoggedIn(const QString& login);


private:
	Account* m_waitingAccount;


};

#endif // WAITINGGAMES_H
