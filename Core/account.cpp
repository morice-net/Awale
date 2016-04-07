#include "account.h"

#include "xmltools.h"

Account::Account(QObject *parent) :
	QObject(parent)
{
}

QString Account::xmlState()
{
	XmlTools tool;
	return tool.xmlFromValue("Login",m_login);
}

QString Account::login() const
{
	return m_login;
}

void Account::setLogin(const QString &login)
{
	if (login != m_login) {
		m_login = login;
		emit loginChanged();
	}
}

QString Account::password() const
{
	return m_password;
}

void Account::setPassword(const QString &password)
{
	if (password != m_password) {
		m_password = password;
		emit passwordChanged();
	}
}

QString Account::email() const
{
	return m_email;
}

void Account::setEmail(const QString &email)
{
	if (email != m_email) {
		m_email = email;
		emit emailChanged();
	}
}



