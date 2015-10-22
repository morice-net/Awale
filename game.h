#ifndef GAME_H
#define GAME_H

#include <QObject>
#include "awale.h"

class Game : public QObject
{
	Q_OBJECT
public:
	explicit Game(QObject *parent = 0);

signals:

public slots:

private:
	Awale m_awale;

};

#endif // GAME_H
