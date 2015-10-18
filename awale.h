#ifndef AWALE_H
#define AWALE_H

#include <QList>

class Awale
{
public:
    Awale();
    void initialize();
    void takeHole(int playerNumber, int holeNumber);
    void draw(int playerNumber, int holeNumber);

    // Getter and Setters
    int playerScore1() const;
    void setPlayerScore1(int playerScore1);

    int playerScore2() const;
    void setPlayerScore2(int playerScore2);

    QList<int> playerHalve1() const;
    void setPlayerHalve1(const QList<int> &playerHalve1);

    QList<int> playerHalve2() const;
    void setPlayerHalve2(const QList<int> &playerHalve2);

    int takenHole() const;
    void setTakenHole(int takenHole);

private:
    int m_playerScore1;
    int m_playerScore2;
    QList<int> m_playerHalve1;
    QList<int> m_playerHalve2;
    int m_takenHole;
};

#endif // AWALE_H
