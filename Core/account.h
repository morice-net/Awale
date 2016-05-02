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

public:
	explicit Account(QObject *parent = 0);
	QString xmlState();

	QString login() const;
	void setLogin(const QString &login);

	QString password() const;
	void setPassword(const QString &password);

    QString iconUrl() const;
    void setIconUrl(const QString &iconUrl);

signals:
	void loginChanged();
	void passwordChanged();
    void iconUrlChanged();

public slots:

private:
	QString m_login;
	QString m_password;
    QString m_iconUrl;
	QWebSocket *m_clients;

};

#endif // ACCOUNT_H
