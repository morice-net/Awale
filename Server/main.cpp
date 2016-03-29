// Qt
#include <QCoreApplication>
#include <QCommandLineParser>
#include <QDebug>


// Shark
#include <shark/Algorithms/Trainers/NBClassifierTrainer.h>
#include <shark/Models/NBClassifier.h>

// Awale
#include <game.h>

#include "awaleserver.h"

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
	QObject::connect(server, &AwaleServer::closed, &app, &QCoreApplication::quit);

	qDebug() << "Server started";
	return app.exec();
}
