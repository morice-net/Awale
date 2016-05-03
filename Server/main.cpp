// Qt
#include <QCoreApplication>
#include <QCommandLineParser>
#include <QDebug>


// Shark
#include <shark/Algorithms/Trainers/NBClassifierTrainer.h>
#include <shark/Models/NBClassifier.h>

// Awale
#include "awaleserver.h"
#include "gamemaker.h"
#include "messagelistener.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

	QCommandLineParser parser;
	parser.setApplicationDescription("AwaleServer is the server of the awale project. Default port is 1234.");
	parser.addHelpOption();

	QCommandLineOption portOption(QStringList() << "p" << "port",
			QCoreApplication::translate("main", "Port for AwaleServer [default: 1234]."),
			QCoreApplication::translate("main", "port"), QLatin1Literal("1234"));
	parser.addOption(portOption);
	parser.process(app);
	int port = parser.value(portOption).toInt();


	AwaleServer *server = new AwaleServer(port);
	GameMaker *gameMaker = new GameMaker(server);
	MessageListener* messageListener = new MessageListener(server);

	QObject::connect(server, SIGNAL(newMessageReceived(QWebSocket*,QString)), messageListener, SLOT(onMessageReceived(QWebSocket*,QString)), Qt::QueuedConnection);

	qDebug() << "Server started";

	Account* newPlayer = new Account();
	newPlayer->setLogin("login");
	newPlayer->setPassword("password");
	newPlayer->setIconUrl("iconUrl");
	newPlayer->addGameResult(false, 2500);

	return app.exec();
}
