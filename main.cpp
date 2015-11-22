#include <QGuiApplication>
#include <QQuickView>
#include <QQuickItem>

#include "Core/game.h"

int main(int argc, char *argv[])
{
	QGuiApplication app(argc, argv);

    QQuickView view(QUrl(QStringLiteral("qrc:/QML/main.qml")));
	QQuickItem *root = view.rootObject();

	Game game;
	game.setRoot(root);

    QObject::connect ( root, SIGNAL(start()), &game, SLOT(updateView()) );
    QObject::connect ( root, SIGNAL(takeHole(int,int)), &game, SLOT(takeHole(int,int)) );

	view.show();
	return app.exec();
}
