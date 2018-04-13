#ifndef MESSAGELISTENER_H
#define MESSAGELISTENER_H

#include <QObject>
#include <QStringList>

QT_FORWARD_DECLARE_CLASS(QWebSocket)

#include "gamemaker.h"
#include "accountcreator.h"
#include "sqlitestorage.h"

class MessageListener : public QObject
{
    Q_OBJECT
public:
    enum MessageType {
        connect,
        createAccount
    };

    explicit MessageListener(QObject *parent = 0);

signals:

public slots:
    void onMessageReceived(QWebSocket* client, QString message);

protected:
    QStringList m_messages;
	AccountCreator m_accountCreator;
	GameMaker m_gameMaker;
    SQLiteStorage m_storage;
};

#endif // MESSAGELISTENER_H
