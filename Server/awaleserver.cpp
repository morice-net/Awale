#include "awaleserver.h"

#include <QWebSocketServer>
#include <QWebSocket>

#include "gamemaker.h"
#include "accountcreator.h"

AwaleServer::AwaleServer(quint16 port, QObject *parent) :
	QObject(parent),
	m_pWebSocketServer(new QWebSocketServer(QStringLiteral("Echo Server"),
											QWebSocketServer::NonSecureMode, this)),
	m_clients()
{
	if (m_pWebSocketServer->listen(QHostAddress::Any, port)) {
		qDebug() << "AwaleServer listening on port" << port;
		connect(m_pWebSocketServer, &QWebSocketServer::newConnection,
				this, &AwaleServer::onNewConnection);
		connect(m_pWebSocketServer, &QWebSocketServer::closed, this, &AwaleServer::closed);
	}
}


AwaleServer::~AwaleServer()
{
	m_pWebSocketServer->close();
    qDeleteAll(m_clients.begin(), m_clients.end());
}

void AwaleServer::onNewConnection()
{
	QWebSocket *socket = m_pWebSocketServer->nextPendingConnection();

	connect(socket, &QWebSocket::textMessageReceived, this, &AwaleServer::processTextMessage);
	connect(socket, &QWebSocket::binaryMessageReceived, this, &AwaleServer::processBinaryMessage);
	connect(socket, &QWebSocket::disconnected, this, &AwaleServer::socketDisconnected);

	m_clients << socket;
}

void AwaleServer::processTextMessage(QString message)
{
	QWebSocket *client = qobject_cast<QWebSocket *>(sender());
	qDebug() << "Message received:" << message;
    if (!client) {
        return;
    }

    QStringList commands = message.split("|");

    // Connect message case
    ;
    if (commands.first() == QStringLiteral("connect")) {
        GameMaker *maker = qobject_cast<GameMaker*>(parent());
        QString playerLogin = commands.at(1);
        int gameId = maker->onLoggedIn(playerLogin, client);
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

void AwaleServer::processBinaryMessage(QByteArray message)
{
	QWebSocket *client = qobject_cast<QWebSocket *>(sender());
	qDebug() << "Binary Message received:" << message;
	if (client) {
		client->sendBinaryMessage(message);
	}
}

void AwaleServer::socketDisconnected()
{
	QWebSocket *client = qobject_cast<QWebSocket *>(sender());
	qDebug() << "socketDisconnected:" << client;
	if (client) {
		m_clients.removeAll(client);
		client->deleteLater();
	}
}
