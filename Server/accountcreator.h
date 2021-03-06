#ifndef ACCOUNTCREATOR_H
#define ACCOUNTCREATOR_H

#include <QObject>
QT_FORWARD_DECLARE_CLASS(QWebSocket)

class Account;

class AccountCreator : public QObject
{
	Q_OBJECT
public:
	explicit AccountCreator(QObject *parent = 0);
	void createAccount(const QString &login, const QString &password, const QString &iconUrl, QWebSocket *client);
	void connectClient(const QString &login, const QString &password, QWebSocket *client);
    Account *accountFromLogin(const QString& login);

public slots:
    void onLoadAccount(const QString &login, const QString &password, const QString &iconUrl, int wins, int games, int elo);

signals:
    void accountCreated(Account* account);
};

#endif // ACCOUNTCREATOR_H
