#pragma once

#include <QObject>

class test : public QObject
{
    Q_OBJECT
public:
    explicit test(QObject *parent = nullptr);
    ~test();

    void testing();
signals:
    void alarm(QString str);

public slots:
    void wake(QString str);
};

