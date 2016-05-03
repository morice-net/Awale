#include "accountcreator.h"

#include <QWebSocket>

#include "account.h"

AccountCreator::AccountCreator(QObject *parent) : QObject(parent)
{

}

void AccountCreator::createAccount(const QString &login, const QString &password, const QString &iconUrl, QWebSocket* client)
{
	for (QObject *accountObj: children()) {
		Account* account = qobject_cast<Account*>(accountObj);
		if (account == NULL) {
			continue;
		}
		if (account->login() == login) {
			client->sendTextMessage("Error|Login already exists, please choose another one");
			return;
		}
	}

	// Account creation, initial params, and stateSending
	Account* newPlayer = new Account(this);
	newPlayer->setLogin(login);
	newPlayer->setPassword(password);
	newPlayer->setIconUrl(iconUrl);
	newPlayer->setClient(client);
	newPlayer->sendStateMessage();
}

QVector<Account *> AccountCreator::accounts()
{
	QVector<Account *> accounts;
	for (QObject *accountObj: children()) {
		Account* account = qobject_cast<Account*>(accountObj);
		if (account == NULL) {
			continue;
		}
		accounts << account;
	}
	return accounts;
}

