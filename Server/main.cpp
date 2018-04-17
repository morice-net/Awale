// Qt
#include <QCoreApplication>
#include <QCommandLineParser>
#include <QDebug>
#include <QWebSocket>


// Shark
#include <shark/Algorithms/Trainers/NBClassifierTrainer.h>
#include <shark/Models/NBClassifier.h>

// Awale
#include "awaleserver.h"
#include "gamemaker.h"
#include "messagelistener.h"

int main(int argc, char *argv[])
{
    QCoreApplication::addLibraryPath("/home/morice/Qt/5.10.0/gcc_64/plugins/");

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


    // DEBUG //
    QWebSocket* client = new QWebSocket;
    messageListener->onMessageReceived(client, "createAccount|Morice|moroce|http://artaud.g.free.fr/Awale/Faces/A02.png");
    messageListener->onMessageReceived(client, "createAccount|Login|Password|http://artaud.g.free.fr/Awale/Faces/A01.png");
    /*
    messageListener->onMessageReceived(client, "createGame|Login");
    messageListener->onMessageReceived(client, "createGame|Morice");
    messageListener->onMessageReceived(client, "takeHole|0|Login|1");
    */
    // DEBUG ///

    QObject::connect(server, SIGNAL(newMessageReceived(QWebSocket*,QString)), messageListener, SLOT(onMessageReceived(QWebSocket*,QString)), Qt::QueuedConnection);

	qDebug() << "Server started";

	return app.exec();
}
