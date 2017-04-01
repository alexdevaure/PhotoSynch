#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "copyfiles.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<CopyFiles>("CopyFiles", 1,0, "CopyFiles");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
