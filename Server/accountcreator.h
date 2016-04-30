#ifndef ACCOUNTCREATOR_H
#define ACCOUNTCREATOR_H

#include <QObject>

class AccountCreator : public QObject
{
    Q_OBJECT
public:
    explicit AccountCreator(QObject *parent = 0);
    void createAccount(const QString &login, const QString &password, const QString &iconUrl);
};

#endif // ACCOUNTCREATOR_H
