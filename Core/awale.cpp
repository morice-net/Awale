#include "awale.h"

// Qt
#include <QStringList>

// Awale
#include "xmltools.h"

Awale::Awale(QObject *parent)
    : QObject(parent)
{
    m_playerHalve1 << 0 << 0 << 0 << 0 << 0 << 0;
    m_playerHalve2 << 0 << 0 << 0 << 0 << 0 << 0;
    m_playerScore1 = 0;
    m_playerScore2 = 0;
    m_takenHole = 0;
    m_playerTurn = 0;
    m_lastPlayed = -1;
}

/*!
 * \brief Awale::initialize init to the classic Awale : 6 holes by halve with 4 stones in each
 */
void Awale::initialize()
{
    setPlayerHalve1(QVector<int>() << 4 << 4 << 4 << 4 << 4 << 4);
    setPlayerHalve2(QVector<int>() << 4 << 4 << 4 << 4 << 4 << 4);
    setPlayerScore1(0);
    setPlayerScore2(0);
    setTakenHole(0);
    setPlayerTurn(1);
    setPlayables(QVector<int>() << 1 << 1 << 1 << 1 << 1 << 1 << 0 << 0 << 0 << 0 << 0 << 0);
}

/*!
 * \brief Awale::takeHole
 * \param playerNumber
 * \param holeNumber
 */
void Awale::takeHole(int playerNumber, int holeNumber)
{
    if (playerNumber == 1) {
        setTakenHole(m_playerHalve1[holeNumber]);
        QVector<int> halve1 = m_playerHalve1;
        halve1[holeNumber] = 0;
        setPlayerHalve1(halve1);
    } else {
        setTakenHole(m_playerHalve2[holeNumber]);
        QVector<int> halve2 = m_playerHalve2;
        halve2[holeNumber] = 0;
        setPlayerHalve2(halve2);
    }
}

/*!
 * \brief Awale::resetHole
 * \param halveNumber
 * \param halve1
 * \param halve2
 * \param holeNumber
 */
void Awale::resetHole(int halveNumber, int holeNumber, QVector<int> &halve1, QVector<int> &halve2)
{
    if (halveNumber == 1) {
        halve1[holeNumber] = 0;
        setPlayerHalve1(halve1);
    } else {
        halve2[holeNumber] = 0;
        setPlayerHalve2(halve2);
    }
}

/*!
 * \brief Awale::draw
 * \param playerNumber
 * \param holeNumber
 */
Awale::Winner Awale::draw(int playerNumber, int holeNumber)
{
    // Note this the last played
    m_lastPlayed = holeNumber + (playerNumber - 1) * 6;

    // Record help sending step by step holes up and down, it will animate the UI
    int halveNumber = playerNumber;
    QVector<int> halve1 = m_playerHalve1;
    QVector<int> halve2 = m_playerHalve2;

    while (m_takenHole > 0) {
        // Next stone deposit
        ++holeNumber;

        // Are we on the next halve
        if (holeNumber >= 6) {
            halveNumber++;
            if (halveNumber > 2){
                halveNumber = 1;
            }
            holeNumber = 0;
        }

        // Take the stone from the taken hole
        setTakenHole(m_takenHole - 1);

        // Put it in the next halve stone
        if (halveNumber == 1) {
            halve1[holeNumber]++;
            setPlayerHalve1( halve1 );
        } else {
            halve2[holeNumber]++;
            setPlayerHalve2( halve2 );
        }
    }

    // Now we eat the stones, take care it is not exactly takeHole
    if ( halveNumber != m_playerTurn) {
        int numberOfStone = halveNumber == 1 ? halve1[holeNumber] : halve2[holeNumber];
        while (numberOfStone == 2 || numberOfStone == 3) {
            if (playerNumber == 1) {
                setPlayerScore1(m_playerScore1 + numberOfStone);
                resetHole(halveNumber, holeNumber, halve1, halve2);
            } else {
                setPlayerScore2(m_playerScore2 + numberOfStone);
                resetHole(halveNumber, holeNumber, halve1, halve2);
            }

            // This hole is empty, let's go to the previous
            holeNumber--;
            if (holeNumber < 0)	{
                break;
            }
            numberOfStone = halveNumber == 1 ? halve1[holeNumber] : halve2[holeNumber];
        }
    }

    // Update the player turn
    setPlayerTurn(m_playerTurn == 1 ? 2 : 1);

    if (m_playerScore1 >= 25) {
        return Player1;
    } else if (m_playerScore2 >= 25) {
        return Player2;
    } else if (m_playerScore1 == 24 && m_playerScore2 == 24) {
        return Draw;
    } else {
        return NoWinner; // Game is not done yet
    }

}

/*!
 * \brief Awale::computePlayable
 */
void Awale::computePlayable()
{
    // Init the vector
    QVector<int> playableVector;
    for (int i = 0; i < 12; ++i) {
        playableVector << 0;
    }

    // Feed the playables
    if (m_playerTurn == 1) {
        for (int i = 0; i < 6; ++i) {
            if (isHungry(i)) {
                continue;
            }
            if (m_playerHalve1.at(i) != 0) {
                playableVector[i] = 1;
            }
        }
    }
    if (m_playerTurn == 2) {
        for (int i = 0; i < 6; ++i) {
            if (isHungry(i)) {
                continue;
            }
            if (m_playerHalve2.at(i) != 0) {
                playableVector[i+6] = 1;
            }
        }
    }

    // Last played hole
    if (m_lastPlayed >= 0) {
        playableVector[m_lastPlayed] = 2;
    }

    // Update the model
    setPlayables(playableVector);
}

/*!
 * \brief Awale::isHungry
 * \param hole
 * \return
 */
bool Awale::isHungry(int hole)
{
    // Init an empty halve
    QVector<int> emptyHalve;
    for (int i = 0; i < 6; i++) {
        emptyHalve << 0;
    }

    // Check what would be next turn
    Awale next;
    next.setPlayerHalve1(m_playerHalve1);
    next.setPlayerHalve2(m_playerHalve2);
    next.setPlayerTurn(m_playerTurn);
    next.takeHole(m_playerTurn,hole);
    next.draw(m_playerTurn,hole);

    // Check if hungry depending on player turn
    if (m_playerTurn == 2 && next.playerHalve1() == emptyHalve) {
        return true;
    } else if (next.playerHalve2() == emptyHalve) {
        return true;
    }

    // Usually it should be not hungry
    return false;
}

/*!
 * \brief Awale::xmlState
 * \return xml of the properties as a string
 */
QString Awale::xmlState()
{
    QStringList xmlCurrentState;
    XmlTools tool;
    xmlCurrentState << "<Awale>";
    xmlCurrentState << tool.xmlFromValue("playerScore1",m_playerScore1);
    xmlCurrentState << tool.xmlFromValue("playerScore2",m_playerScore2);

    xmlCurrentState << tool.xmlFromValue("playerHalve1",m_playerHalve1);
    xmlCurrentState << tool.xmlFromValue("playerHalve2",m_playerHalve2);

    xmlCurrentState << tool.xmlFromValue("takenHole",m_takenHole);
    xmlCurrentState << tool.xmlFromValue("playerTurn",m_playerTurn);
    xmlCurrentState << tool.xmlFromValue("playables",m_playables);
    xmlCurrentState << tool.xmlFromValue("lastPlayed",m_lastPlayed);
    xmlCurrentState << "</Awale>";

    return xmlCurrentState.join("");
}

/* Getters & Setters */

int Awale::playerScore1() const
{
    return m_playerScore1;
}

void Awale::setPlayerScore1(int playerScore1)
{
    if (playerScore1 == m_playerScore1) {
        return;
    }

    m_playerScore1 = playerScore1;
}

int Awale::playerScore2() const
{
    return m_playerScore2;
}

void Awale::setPlayerScore2(int playerScore2)
{
    if (playerScore2 == m_playerScore2) {
        return;
    }
    if (playerScore2 >= 25) {
        return;
    }

    if (m_playerScore1 == 24 && playerScore2 == 24 ) {
        return;
    }

    m_playerScore2 = playerScore2;
}

QVector<int> Awale::playerHalve1() const
{
    return m_playerHalve1;
}

void Awale::setPlayerHalve1(const QVector<int> &playerHalve1)
{
    if (playerHalve1 != m_playerHalve1) {
        m_playerHalve1 = playerHalve1;
    }
}

QVector<int> Awale::playerHalve2() const
{
    return m_playerHalve2;
}

void Awale::setPlayerHalve2(const QVector<int> &playerHalve2)
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

int Awale::playerTurn() const
{
    return m_playerTurn;
}

void Awale::setPlayerTurn(int playerTurn)
{
    m_playerTurn = playerTurn;
}

QVector<int> Awale::playables() const
{
    return m_playables;
}

void Awale::setPlayables(const QVector<int> &playables)
{
    m_playables = playables;
}

int Awale::lastPlayed() const
{
    return m_lastPlayed;
}

void Awale::setLastPlayed(int lastPlayed)
{
    m_lastPlayed = lastPlayed;
}


