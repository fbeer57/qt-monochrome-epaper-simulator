#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "ImageItem.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    qmlRegisterType<ImageItem>("myextension", 1, 0, "ImageItem");
    QQmlApplicationEngine engine(QUrl(QStringLiteral("qrc:/src/qml/main.qml")));
    
    return app.exec();
}

