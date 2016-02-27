#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QQuickItem>

#include "awale.h"
#include "examplefeeder.h"

class Game : public QObject
{
	Q_OBJECT
public:
	enum Mode
	{
		Solo,
        Versus,
        Learning
	};

	explicit Game(QObject *parent = 0);

	QQuickItem *root() const;
	void setRoot(QQuickItem *root);
    void playRandom();

signals:

public slots:
	void updateView();
	void gameDone(Awale::Winner winner);
	// Callable from view
	void onStart(int mode);
	void onTakeHole(int player, int holeNumber);
	void onCPUTakeHole();
	void onRevert();

private:
	QQuickItem *m_root;
	QVector<Awale> m_awales;
    QVector<int> m_plays;
    Mode m_mode;
    ExampleFeeder m_feeder;
    Awale::Winner m_isThereAWinner;

};

#endif // GAME_H
