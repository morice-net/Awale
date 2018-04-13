#include "account.h"

#include <QWebSocket>
#include <QMetaProperty>
#include <QDebug>

#include "xmltools.h"

Account::Account(QObject *parent) :
	QObject(parent), m_login(), m_password(), m_iconUrl(), m_wins(0), m_games(0), m_elo(2000), m_client(NULL)
{
    setObjectName("account");
}

void Account::sendStateMessage()
{
	if (m_client == NULL) {
		return;
	}

    XmlTools tool;
    m_client->sendTextMessage(tool.header() + xmlState() + tool.footer());
}

QString Account::xmlState()
{
    QString fullXml("<Account>");
	XmlTools tool;

	for (int i = 1; i < metaObject()->propertyCount(); ++i) {
		QMetaProperty propertyi = metaObject()->property(i);
		fullXml.append(tool.xmlFromValue(propertyi.name(),propertyi.read(this).toString()));
	}
    fullXml.append("</Account>");

	return fullXml;
}

void Account::addGameResult(bool win, int adversaryElo)
{
	m_games++;
	if (win) {
		m_wins++;
		// Compute the elo in win case
		int elo;
		if (m_elo == adversaryElo) {
			elo = 5;
		} else if (adversaryElo > m_elo) {
			elo = (0.2 * (adversaryElo - m_elo));
		} else {
			elo = (10 / (m_elo - adversaryElo));
		}
		m_elo += elo;
	} else {
		// Compute the elo in lose case
		int elo;
		if (m_elo == adversaryElo) {
			elo = 5;
		} else if (adversaryElo > m_elo) {
			elo = (10 / (m_elo - adversaryElo));
		} else {
			elo = (0.2 * (adversaryElo - m_elo));
		}

		m_elo -= elo;
	}
	sendStateMessage();
}

void Account::disconnected()
{
	if (m_client != NULL) {
		return;
	}
	delete m_client;
	m_client = NULL;
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

QString Account::iconUrl() const
{
	return m_iconUrl;
}

void Account::setIconUrl(const QString &email)
{
	if (email != m_iconUrl) {
		m_iconUrl = email;
		emit iconUrlChanged();
	}
}

int Account::wins() const
{
	return m_wins;
}

void Account::setWins(int wins)
{
	m_wins = wins;
}

int Account::games() const
{
	return m_games;
}

void Account::setGames(int games)
{
	m_games = games;
}

int Account::elo() const
{
	return m_elo;
}

void Account::setElo(int elo)
{
	m_elo = elo;
}

QWebSocket *Account::client() const
{
	return m_client;
}

void Account::setClient(QWebSocket *client)
{
	m_client = client;
}



