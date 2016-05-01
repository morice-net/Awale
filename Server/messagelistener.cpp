#include "messagelistener.h"

// Qt
#include <QWebSocket>x

// Server
#include "gamemaker.h"
#include "accountcreator.h"

MessageListener::MessageListener(QObject *parent) : QObject(parent)
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

    // Account creation
    if (commands.first() == QStringLiteral("accountCreation")) {
        AccountCreator accountCreator(this);
        accountCreator.createAccount(commands.at(1),commands.at(2),commands.at(3));
    }
}

