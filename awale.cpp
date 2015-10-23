#include "awale.h"

Awale::Awale()
{
	m_playerHalve1 << 0 << 0 << 0 << 0 << 0 << 0;
	m_playerHalve2 << 0 << 0 << 0 << 0 << 0 << 0;
	m_playerScore1 = 0;
	m_playerScore2 = 0;
	m_takenHole = 0;
	m_playerTurn = 0;
}

/*!
 * \brief Awale::initialize init to the classic Awale : 6 holes by halve with 4 stones in each
 */
void Awale::initialize()
{
	setPlayerHalve1(QList<int>() << 4 << 4 << 4 << 4 << 4 << 4);
	setPlayerHalve2(QList<int>() << 4 << 4 << 4 << 4 << 4 << 4);
	setPlayerScore1(0);
	setPlayerScore2(0);
	setTakenHole(0);
	setPlayerTurn(1);
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
        QList<int> halve1 = m_playerHalve1;
        halve1[holeNumber] = 0;
        setPlayerHalve1(halve1);
	} else {
		setTakenHole(m_playerHalve2[holeNumber]);
		QList<int> halve2 = m_playerHalve2;
		halve2[holeNumber] = 0;
		setPlayerHalve2(halve2);
	}
}

/*!
 * \brief Awale::draw
 * \param playerNumber
 * \param holeNumber
 */
void Awale::draw(int playerNumber, int holeNumber)
{
	// Record help sending step by step holes up and down, it will animate the UI
	int halveNumber = playerNumber;
	QList<int> halve1 = m_playerHalve1;
	QList<int> halve2 = m_playerHalve2;

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
	int numberOfStone = halveNumber == 1 ? halve1[holeNumber] : halve2[holeNumber];
	while (numberOfStone == 2 || numberOfStone == 3) {
		if (playerNumber == 1) {
			setPlayerScore1(m_playerScore1 + numberOfStone);
			if (halveNumber == 1) {
				halve1[holeNumber] = 0;
				setPlayerHalve1(halve1);
			} else {
				halve2[holeNumber] = 0;
				setPlayerHalve2(halve2);

			}
		}
		numberOfStone = halveNumber == 1 ? halve1[holeNumber] : halve2[holeNumber];
	}

	// Update the player turn
	//TODO check nothing in the opponent halve is empty maybe :-)
	setPlayerTurn(m_playerTurn == 1 ? 2 : 1);
}

/* Getters & Setters */

int Awale::playerScore1() const
{
    return m_playerScore1;
}

void Awale::setPlayerScore1(int playerScore1)
{
	if (playerScore1 != m_playerScore1) {
		m_playerScore1 = playerScore1;
		emit playerScore1Changed();
	}
}
int Awale::playerScore2() const
{
    return m_playerScore2;
}

void Awale::setPlayerScore2(int playerScore2)
{
	if (playerScore2 != m_playerScore2) {
		m_playerScore2 = playerScore2;
		emit playerScore2Changed();
	}
}
QList<int> Awale::playerHalve1() const
{
    return m_playerHalve1;
}

void Awale::setPlayerHalve1(const QList<int> &playerHalve1)
{
	if (playerHalve1 != m_playerHalve1) {
		m_playerHalve1 = playerHalve1;
		emit playerHalve1Changed();
	}
}
QList<int> Awale::playerHalve2() const
{
    return m_playerHalve2;
}

void Awale::setPlayerHalve2(const QList<int> &playerHalve2)
{
	if (playerHalve2 != m_playerHalve2) {
		m_playerHalve2 = playerHalve2;
		emit playerHalve2Changed();
	}
}
int Awale::takenHole() const
{
    return m_takenHole;
}

void Awale::setTakenHole(int takenHole)
{
	if (takenHole != m_takenHole) {
		m_takenHole = takenHole;
		emit takenHoleChanged();
	}
}
int Awale::playerTurn() const
{
	return m_playerTurn;
}

void Awale::setPlayerTurn(int playerTurn)
{
	if (m_playerTurn != playerTurn)
	{
		m_playerTurn = playerTurn;
		emit playerTurnChanged();
	}
}






