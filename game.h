#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QQuickItem>

#include "awale.h"

class Game : public QObject
{
	Q_OBJECT
public:
	explicit Game(QObject *parent = 0);

	QQuickItem *root() const;
	void setRoot(QQuickItem *root);

	void initialize();
signals:

public slots:
	void updateView();
	void takeHole(int player, int holeNumber);

private:
	QQuickItem *m_root;
	Awale m_awale;

};

#endif // GAME_H
