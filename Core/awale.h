#ifndef AWALE_H
#define AWALE_H

#include <QObject>
#include <QVector>

class Awale : public QObject
{
	Q_OBJECT

	Q_PROPERTY(int playerScore1 READ playerScore1 WRITE setPlayerScore1)
	Q_PROPERTY(int playerScore2 READ playerScore2 WRITE setPlayerScore2)
	Q_PROPERTY(QVector<int> playerHalve1 READ playerHalve1 WRITE setPlayerHalve1)
	Q_PROPERTY(QVector<int> playerHalve2 READ playerHalve2 WRITE setPlayerHalve2)
	Q_PROPERTY(int takenHole READ takenHole WRITE setTakenHole)
	Q_PROPERTY(int playerTurn READ playerTurn WRITE setPlayerTurn)
	Q_PROPERTY(QVector<int> playables READ playables WRITE setPlayables)
	Q_PROPERTY(int lastPlayed READ lastPlayed WRITE setLastPlayed)

public:
	enum Winner {
		NoWinner,
		Player1,
		Player2,
		Draw
	};

	Awale(QObject* parent = 0);
    void initialize();
    void takeHole(int playerNumber, int holeNumber);
	void resetHole(int &halveNumber, int &holeNumber, QVector<int> &halve1, QVector<int> &halve2);
	Winner draw(int playerNumber, int holeNumber);
	void computePlayable();
    bool isHungry(int hole);
	QString xmlState();

    // Getter and Setters
    int playerScore1() const;
    void setPlayerScore1(int playerScore1);

    int playerScore2() const;
    void setPlayerScore2(int playerScore2);

	QVector<int> playerHalve1() const;
	void setPlayerHalve1(const QVector<int> &playerHalve1);

	QVector<int> playerHalve2() const;
	void setPlayerHalve2(const QVector<int> &playerHalve2);

    int takenHole() const;
    void setTakenHole(int takenHole);

	int playerTurn() const;
	void setPlayerTurn(int playerTurn);

	QVector<int> playables() const;
	void setPlayables(const QVector<int> &playables);

	int lastPlayed() const;
	void setLastPlayed(int lastPlayed);

private:
	int m_playerScore1;
	int m_playerScore2;
	QVector<int> m_playerHalve1;
	QVector<int> m_playerHalve2;
    int m_takenHole;
	int m_playerTurn; // 1 or 2 while playing
	QVector<int> m_playables;
	int m_lastPlayed;
};

#endif // AWALE_H
