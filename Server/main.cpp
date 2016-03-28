// Qt
#include <QCoreApplication>
#include <QDebug>


// Shark
#include <shark/Algorithms/Trainers/NBClassifierTrainer.h>
#include <shark/Models/NBClassifier.h>

// Awale
#include <game.h>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    Game game;

    qDebug() << "Server starting";
	return app.exec();
}
