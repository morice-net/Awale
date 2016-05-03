#include "messagelistener.h"

// Qt
#include <QWebSocket>

// Server
#include "gamemaker.h"

MessageListener::MessageListener(QObject *parent) : QObject(parent), m_accountCreator(this)
{

}

void MessageListener::onMessageReceived(QWebSocket *client, QString message)
{

    QStringList commands = message.split("|");

    // Connect message case
    ;
    if (commands.first() == QStringLiteral("createGame")) {
        GameMaker *maker = qobject_cast<GameMaker*>(parent());
        QString playerLogin = commands.at(1);
        int gameId = maker->createGame(playerLogin, client);
        if (gameId >= 0) {
            Game* game = maker->gameById(gameId);
            if (!game) {
                return;
            }
            qobject_cast<QWebSocket *>(game->player1()->parent())->sendTextMessage(game->stateOfTheWorld());
            client->sendTextMessage(game->stateOfTheWorld());
        } else {
            client->sendTextMessage("waiting");
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

