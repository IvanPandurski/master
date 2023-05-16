#include "test.h"
#include "QDebug"

test::test(QObject *parent)
    : QObject{parent}
{
    qInfo() << this << "Constructor \n";
}

test::~test()
{
    qInfo() << this << "Destructor \n";
}

void test::testing()
{
    QString str {"Alarm is ringing, wake up"};

    emit alarm(str);
}

void test::wake(QString str)
{
    qInfo() << this << " From: " << sender() << str << "\n";
}
