#include "awaleserver.h"

#include <QWebSocketServer>
#include <QWebSocket>

#include "messagelistener.h"

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
    } else {
        qDebug() << "AwaleServer error on connexion" << port;
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

    emit newMessageReceived(client, message);
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
