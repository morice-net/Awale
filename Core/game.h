#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QQuickItem>

#include "awale.h"

class Game : public QObject
{
	Q_OBJECT
public:
	enum Mode
	{
		Solo,
		Versus
	};

	explicit Game(QObject *parent = 0);

	QQuickItem *root() const;
	void setRoot(QQuickItem *root);

signals:

public slots:
	void updateView();
	void gameDone(int winner);
	void onStart(int mode);
	void takeHole(int player, int holeNumber);

private:
	QQuickItem *m_root;
	Awale m_awale;
	Mode m_mode;

};

#endif // GAME_H
