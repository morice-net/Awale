#ifndef MESSAGELISTENER_H
#define MESSAGELISTENER_H

#include <QObject>
#include <QStringList>

QT_FORWARD_DECLARE_CLASS(QWebSocket)

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
};

#endif // MESSAGELISTENER_H
