#ifndef AWALE_H
#define AWALE_H

#include <QObject>
#include <QVector>

class Awale
{
public:
	enum Winner {
		NoWinner,
		Player1,
		Player2,
		Draw
	};

    Awale();
    void initialize();
    void takeHole(int playerNumber, int holeNumber);
	void resetHole(int &halveNumber, int &holeNumber, QVector<int> &halve1, QVector<int> &halve2);
	Winner draw(int playerNumber, int holeNumber);
	void computePlayable();

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

	QVector<bool> playables() const;
	void setPlayables(const QVector<bool> &playables);

private:
	int m_playerScore1;
	int m_playerScore2;
	QVector<int> m_playerHalve1;
	QVector<int> m_playerHalve2;
    int m_takenHole;
	int m_playerTurn; // 1 or 2 while playing
	QVector<bool> m_playables;
};

#endif // AWALE_H
