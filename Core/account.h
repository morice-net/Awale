#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QObject>

class Account : public QObject
{
	Q_OBJECT

	Q_PROPERTY(QString login READ login WRITE setLogin NOTIFY loginChanged)
	Q_PROPERTY(QString password READ password WRITE setPassword NOTIFY passwordChanged)
	Q_PROPERTY(QString email READ email WRITE setEmail NOTIFY emailChanged)

public:
	explicit Account(QObject *parent = 0);
	QString xmlState();

	QString login() const;
	void setLogin(const QString &login);

	QString password() const;
	void setPassword(const QString &password);

	QString email() const;
	void setEmail(const QString &email);

signals:
	void loginChanged();
	void passwordChanged();
	void emailChanged();

public slots:

private:
	QString m_login;
	QString m_password;
    QString m_email;

};

#endif // ACCOUNT_H
