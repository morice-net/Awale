#include <QGuiApplication>
#include <QQuickView>
#include <QQuickItem>


int main(int argc, char *argv[])
{
	QGuiApplication app(argc, argv);

	QQuickView view(QUrl(QStringLiteral("qrc:/main.qml")));
	QObject *root = view.rootObject();

	// Connector connector;
	// QObject::connect ( root, SIGNAL(connect()), &connector, SLOT(onConnect()) );


	view.show();
	return app.exec();
}
