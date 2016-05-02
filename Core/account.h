#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QObject>
QT_FORWARD_DECLARE_CLASS(QWebSocket)


class Account : public QObject
{
	Q_OBJECT

	Q_PROPERTY(QString login READ login WRITE setLogin NOTIFY loginChanged)
	Q_PROPERTY(QString password READ password WRITE setPassword NOTIFY passwordChanged)
    Q_PROPERTY(QString iconUrl READ iconUrl WRITE setIconUrl NOTIFY iconUrlChanged)
	Q_PROPERTY(int wins READ wins WRITE setWins)
	Q_PROPERTY(int games READ games WRITE setGames)
	Q_PROPERTY(int elo READ elo WRITE setElo)

public:
	explicit Account(QObject *parent = 0);
	QString xmlState();
	void addGameResult(bool win, int adversaryElo);
	void disconnected();

	QString login() const;
	void setLogin(const QString &login);

	QString password() const;
	void setPassword(const QString &password);

    QString iconUrl() const;
    void setIconUrl(const QString &iconUrl);

	int wins() const;
	void setWins(int wins);

	int games() const;
	void setGames(int games);

	int elo() const;
	void setElo(int elo);

	QWebSocket *client() const;
	void setClient(QWebSocket *client);

signals:
	void loginChanged();
	void passwordChanged();
	void iconUrlChanged();

public slots:

private:
	QString m_login;
	QString m_password;
    QString m_iconUrl;
	int		m_wins;
	int		m_games;
	int		m_elo;
	QWebSocket *m_client;
};

#endif // ACCOUNT_H
