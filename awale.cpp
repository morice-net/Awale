#include "awale.h"

Awale::Awale()
{
}

void Awale::initialize()
{
    m_playerHalve1 << 4 << 4 << 4 << 4 << 4 << 4;
    m_playerHalve2 << 4 << 4 << 4 << 4 << 4 << 4;
    m_playerScore1 = 0;
    m_playerScore2 = 0;
    m_takenHole = 0;
}

void Awale::takeHole(int playerNumber, int holeNumber)
{
    if (playerNumber == 1) {
        setTakenHole(m_playerHalve1[holeNumber]);
        QList<int> halve1 = m_playerHalve1;
        halve1[holeNumber] = 0;
        setPlayerHalve1(halve1);
    }
}

void Awale::draw(int playerNumber, int holeNumber)
{
    int i = holeNumber;
    while (m_takenHole > 0) {
        // Next stone deposit
        ++i;
        // Are we on the next halve
        if (i > 6) {
            playerNumber++;
            if (playerNumber > 2){
                playerNumber = 1;
            }
        }
        // Take the stone from the taken hole
        setTakenHole(m_takenHole - 1);
        // Put it in the next halve stone
        if (playerNumber == 1) {
            QList<int> halve1 = m_playerHalve1;
            halve1[i]++;
            setPlayerHalve1( halve1 );
        } else {
            QList<int> halve2 = m_playerHalve2;
            halve2[i]++;
            setPlayerHalve2( halve2 );
        }
    }
}

int Awale::playerScore1() const
{
    return m_playerScore1;
}

void Awale::setPlayerScore1(int playerScore1)
{
    m_playerScore1 = playerScore1;
}
int Awale::playerScore2() const
{
    return m_playerScore2;
}

void Awale::setPlayerScore2(int playerScore2)
{
    m_playerScore2 = playerScore2;
}
QList<int> Awale::playerHalve1() const
{
    return m_playerHalve1;
}

void Awale::setPlayerHalve1(const QList<int> &playerHalve1)
{
    m_playerHalve1 = playerHalve1;
}
QList<int> Awale::playerHalve2() const
{
    return m_playerHalve2;
}

void Awale::setPlayerHalve2(const QList<int> &playerHalve2)
{
    m_playerHalve2 = playerHalve2;
}
int Awale::takenHole() const
{
    return m_takenHole;
}

void Awale::setTakenHole(int takenHole)
{
    m_takenHole = takenHole;
}





