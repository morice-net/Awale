#include "messagelistener.h"

// Qt
#include <QWebSocket>

// Server
#include "gamemaker.h"

MessageListener::MessageListener(QObject *parent) : QObject(parent), m_accountCreator(this), m_gameMaker(this)
{

}

void MessageListener::onMessageReceived(QWebSocket *client, QString message)
{

	QStringList commands = message.split("|");

	// Create game
	if (commands.first() == QStringLiteral("createGame")) {
		Account* account = m_accountCreator.accountFromLogin(commands.at(1));
		if (account != NULL) {
			m_gameMaker.createGame(account, client);
		}
	}

	// Client connection
	if (commands.first() == QStringLiteral("clientConnection")) {
		m_accountCreator.connectClient(commands.at(1), commands.at(2), client);
	}

	// Account creation
	if (commands.first() == QStringLiteral("accountCreation")) {
		m_accountCreator.createAccount(commands.at(1), commands.at(2), commands.at(3), client);
	}
}

