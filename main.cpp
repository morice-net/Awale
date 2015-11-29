#include <QGuiApplication>
#include <QQuickView>
#include <QQuickItem>
#include <QQmlEngine>

#include "Core/game.h"

int main(int argc, char *argv[])
{
	QGuiApplication app(argc, argv);

    QQuickView view(QUrl(QStringLiteral("qrc:/QML/main.qml")));
	QQuickItem *root = view.rootObject();
    QQmlEngine *engine = view.engine();
	Game game;
	game.setRoot(root);

	QObject::connect ( root, SIGNAL(start(int)), &game, SLOT(onStart(int)) );
    QObject::connect ( root, SIGNAL(takeHole(int,int)), &game, SLOT(takeHole(int,int)) );
    QObject::connect ( engine, &QQmlEngine::quit, &app, &QCoreApplication::quit );

	view.show();
	return app.exec();
}
