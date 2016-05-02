#include "accountcreator.h"

#include "account.h"

AccountCreator::AccountCreator(QObject *parent) : QObject(parent)
{

}

void AccountCreator::createAccount(const QString &login, const QString &password, const QString &iconUrl)
{
	Account* newPlayer = new Account(this);
	newPlayer->setLogin(login);
	newPlayer->setPassword(password);
	newPlayer->setIconUrl(iconUrl);

}

