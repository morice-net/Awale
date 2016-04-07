#ifndef GAME_H
#define GAME_H

#include <QObject>

#include "awale.h"

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

    void playRandom();
	QString stateOfTheWorld();

signals:

public slots:
	void gameDone(Awale::Winner winner);
	// Callable from view
	void onStart(int mode);
	void onTakeHole(int player, int holeNumber);
	void onCPUTakeHole();
	void onRevert();

private:
	QVector<Awale*> m_awales;
    QVector<int> m_plays;
    Mode m_mode;
    //ExampleFeeder m_feeder;
    Awale::Winner m_isThereAWinner;
	QString m_player1login;
	QString m_player2login;

};

#endif // GAME_H
