#include <QtCore/QCoreApplication>
#include <QtWebSockets/qwebsocketserver.h>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::cout << "Hello wordld\n";
    return a.exec();
}
