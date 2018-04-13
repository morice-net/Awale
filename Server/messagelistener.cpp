#include "messagelistener.h"

// Qt
#include <QWebSocket>

// Server
#include "gamemaker.h"

MessageListener::MessageListener(QObject *parent) : QObject(parent), m_accountCreator(this), m_gameMaker(this), m_storage(this)
{
    QObject::connect(&m_accountCreator, SIGNAL(accountCreated(Account*)), &m_storage, SLOT(onAccountCreated(Account*)));
}

void MessageListener::onMessageReceived(QWebSocket *client, QString message)
{

	QStringList commands = message.split("|");

	// Launch game
	if (commands.first() == QStringLiteral("launchGame")) {
		Account* account = m_accountCreator.accountFromLogin(commands.at(1));
		if (account != NULL) {
			m_gameMaker.launchGame(account);
		}
	}

	// Create game
	if (commands.first() == QStringLiteral("createGame")) {
		Account* account = m_accountCreator.accountFromLogin(commands.at(1));
		if (account != NULL) {
			m_gameMaker.createGame(account);
		}
	}

	// Cancel game
	if (commands.first() == QStringLiteral("abortGame")) {
		Account* account = m_accountCreator.accountFromLogin(commands.at(2));
		if (account != NULL) {
			m_gameMaker.abortGame(commands.at(1).toInt(), account);
		}
	}

	// A player has taken a hole
	if (commands.first() == QStringLiteral("takeHole")) {
		Account* account = m_accountCreator.accountFromLogin(commands.at(2));
		if (account != NULL) {
			m_gameMaker.takeHole(commands.at(1).toInt(), account, commands.at(3).toInt());
		}
	}

	// Client connection
    if (commands.first() == QStringLiteral("connectClient")) {
		m_accountCreator.connectClient(commands.at(1), commands.at(2), client);
	}

	// Account creation
    if (commands.first() == QStringLiteral("createAccount")) {
		m_accountCreator.createAccount(commands.at(1), commands.at(2), commands.at(3), client);
	}
}

