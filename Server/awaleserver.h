#ifndef AWALESERVER_H
#define AWALESERVER_H

#include <QObject>

QT_FORWARD_DECLARE_CLASS(QWebSocketServer)
QT_FORWARD_DECLARE_CLASS(QWebSocket)

class AwaleServer : public QObject
{
	Q_OBJECT
public:
	explicit AwaleServer(quint16 port, QObject *parent = Q_NULLPTR);
	~AwaleServer();

Q_SIGNALS:
	void closed();


private Q_SLOTS:
	void onNewConnection();
	void processTextMessage(QString message);
	void processBinaryMessage(QByteArray message);
	void socketDisconnected();

private:
	QWebSocketServer *m_pWebSocketServer;
	QList<QWebSocket *> m_clients;
	bool m_debug;


};

#endif // AWALESERVER_H
