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
	void sendStateOfTheWorld();
	void takeHole(Account* account, int holeNumber);
	void takeHole(int player, int holeNumber);

	Account *player1() const;
	void setPlayer1(Account *player1);

	Account *player2() const;
	void setPlayer2(Account *player2);

    int id() const;
    void setId(int id);

public slots:
	// Callable from view
	void onCPUTakeHole();
	void onRevert();

signals:
	void gameDone();

private:
	QVector<Awale*> m_awales;
    QVector<int> m_plays;
    Mode m_mode;
    //ExampleFeeder m_feeder;
    Awale::Winner m_isThereAWinner;
	int m_id;
	Account *m_player1;
	Account *m_player2;

	// Intern methods
	QString stateOfTheWorld() const;
};

#endif // GAME_H
