#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include<QtQml>
#include "jeu2048.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    jeu2048 ajeu2048;

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("jeu",&ajeu2048);
//    engine.rootContext()->setContextProperty("valeurTuile2",&ajeu2048);
//    engine.rootContext()->setContextProperty("valeurTuile3",&ajeu2048);
//    engine.rootContext()->setContextProperty("valeurTuile4",&ajeu2048);
//    engine.rootContext()->setContextProperty("valeurTuile5",&ajeu2048);
//    engine.rootContext()->setContextProperty("valeurTuile6",&ajeu2048);
//    engine.rootContext()->setContextProperty("valeurTuile7",&ajeu2048);
//    engine.rootContext()->setContextProperty("valeurTuile8",&ajeu2048);
//    engine.rootContext()->setContextProperty("valeurTuile9",&ajeu2048);
//    engine.rootContext()->setContextProperty("valeurTuile10",&ajeu2048);
//    engine.rootContext()->setContextProperty("valeurTuile11",&ajeu2048);
//    engine.rootContext()->setContextProperty("valeurTuile12",&ajeu2048);
//    engine.rootContext()->setContextProperty("valeurTuile13",&ajeu2048);
//    engine.rootContext()->setContextProperty("valeurTuile14",&ajeu2048);
//    engine.rootContext()->setContextProperty("valeurTuile15",&ajeu2048);
//    engine.rootContext()->setContextProperty("valeurTuile16",&ajeu2048);

    engine.rootContext()->setContextProperty("valeurCurrentScore",&ajeu2048);
    engine.rootContext()->setContextProperty("valeurMeilleurScore",&ajeu2048);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
