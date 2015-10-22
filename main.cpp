#include <QGuiApplication>
#include <QQuickView>
#include <QQuickItem>

#include "game.h"

int main(int argc, char *argv[])
{
	QGuiApplication app(argc, argv);

	QQuickView view(QUrl(QStringLiteral("qrc:/main.qml")));
	QObject *root = view.rootObject();

	// Connector connector;
	// QObject::connect ( root, SIGNAL(connect()), &connector, SLOT(onConnect()) );

	Awale awale;
	awale.initialize();

	root->setProperty("playerScore1", awale.playerScore1());
	root->setProperty("playerScore2", awale.playerScore2());
	view.show();
	return app.exec();
}
