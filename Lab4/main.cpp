#include <QQmlApplicationEngine>
#include <QGuiApplication>
#include <apartmentlist.h>
#include <QQmlContext>

int main(int argc, char* argv[]) {
auto app = QGuiApplication(argc, argv);
QLocale::setDefault(QLocale::c());
qmlRegisterType<ApartmentList>("ApartmentList", 1, 0, "ApartmentList");
QQmlApplicationEngine engine;
engine.load("qrc:/main.qml");
return QGuiApplication::exec();
}


