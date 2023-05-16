#pragma once
#include <QFile>
#include "QIODevice"
#include "QDebug"
#include "QVariant"

class File
{

public:
    File(const QString& path) : file_{path} {}

    template<class T>
    void write(const T& data, bool append = true)
    {
        if(!file_.open(append ? QIODevice::Append
                               : QIODevice::WriteOnly))
        {
            qCritical() << "Cannot open file \n";
            file_.close();

            return;
        }

        qInfo() << " File is ready for writing.. \n";

        QDataStream out{&file_};
        out.setVersion(QDataStream::Qt_6_4);

        qInfo() << "Data to be saved: ";
        out << data;

        file_.close();
    }

    template<class T>
    void read(T& data)
    {

        if(!file_.open(QIODevice::ReadOnly))
        {
            qCritical() << "Cannot open file \n" << file_.errorString();
            file_.close();

            return;
        }

        QDataStream in{&file_};

        if(in.version() != QDataStream::Qt_6_4)
        {
            qCritical() << "Invalid file version";
            file_.close();
            return;
        }

        qInfo() << "File ready to read...";

        qInfo() << "Data stored in file: \n";
        while(!in.atEnd())
        {
            in >> data;
            //        qInfo() << data;
        }


        file_.close();

    }

private:

    QFile file_;
};

