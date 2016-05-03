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
	QVector<Account *> accounts();
};

#endif // ACCOUNTCREATOR_H
