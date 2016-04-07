#ifndef GAME_H
#define GAME_H

#include <QObject>

#include "awale.h"
#include "account.h"

class Game : public QObject
{
	Q_OBJECT
public:
	enum Mode
	{
		Solo,
        Versus,
        Learning
	};

	explicit Game(QObject *parent = 0);

	void start(int mode);
    void playRandom();
	QString stateOfTheWorld();

	Account *player1() const;
	void setPlayer1(Account *player1);

	Account *player2() const;
	void setPlayer2(Account *player2);

signals:

public slots:
	void gameDone(Awale::Winner winner);
	// Callable from view
	void onTakeHole(int player, int holeNumber);
	void onCPUTakeHole();
	void onRevert();

private:
	QVector<Awale*> m_awales;
    QVector<int> m_plays;
    Mode m_mode;
    //ExampleFeeder m_feeder;
    Awale::Winner m_isThereAWinner;
	int m_id;
	Account *m_player1;
	Account *m_player2;

};

#endif // GAME_H
