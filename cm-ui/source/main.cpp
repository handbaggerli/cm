#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <controllers/master-controller.h>
#include <QQmlContext>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    const QUrl url(QStringLiteral("qrc:/views/MasterView.qml"));

    qmlRegisterType<cm::controllers::MasterController>("CM", 1, 0, "MasterController");
    cm::controllers::MasterController masterController;

    QQmlApplicationEngine engine;           
    engine.rootContext()->setContextProperty("masterController", &masterController);
    engine.load(url);

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
