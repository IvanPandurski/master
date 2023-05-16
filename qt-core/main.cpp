#include <QCoreApplication>
#include "serialization.h"
#include "test.h"

#include <QScopedPointer>
#include <QSharedPointer>

#include "settings.h"
#include "file.h"
#include "serialization.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //simple QObject
    {
        test t;
        t.setObjectName("Test");
    }
    // Signals and slots
    {
//        test alarm;
//        alarm.setObjectName("Alarm");
//        test person;
//        person.setObjectName("Person");

//        QObject::connect(&alarm, &test::alarm, &person, &test::wake);

//        alarm.testing();
    }

    //QScopedPointer and QSharedPointer

    {
//        QScopedPointer<test> sc_ptr {new test()};
//        sc_ptr->setObjectName("Scoped Pointer");
//        qInfo() << sc_ptr.data();
    }

    {
//        QSharedPointer<test> sh_ptr {new test()};
//        sh_ptr->setObjectName("Shared Pointer");

//        qInfo() << sh_ptr.data();
    }

    QCoreApplication::setApplicationName("Test");
    QCoreApplication::setOrganizationName("Test");

    //QSettings
    {

//        Settings settings {};

//        settings.addData("Pesho", 33, "human");
//        settings.addData("Gosho", 33, "human");

//        settings.addData("Koti", 2, "cats");
//        settings.addData("Muri", 1, "cats");

//        settings.addData("Me", 1);


//        settings.sync();

//        settings.readInfo();

    }


    //QFile
//    {
        File file{"test.txt"};

//        serialization sr;
//        qInfo() << &sr;

//        sr.fill();

//        qInfo() << sr.getName();
//        qInfo() << sr.getData();

//        file.write<serialization>(sr);

        serialization sr2;
        file.read<serialization>(sr2);

        qInfo() << sr2.getName();
        qInfo() << sr2.getData();

//    }

    return a.exec();
}
