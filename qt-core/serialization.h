#pragma once
#include <QObject>
#include "QMap"
#include "qdebug.h"

class serialization : public QObject
{
    using str_map = QMap<QString, QString>;
    Q_OBJECT
public:
    explicit serialization(QObject *parent = nullptr) {}

    void fill();

    inline void setName(const QString& name) { name_ = name; }
    inline void setData(const str_map& data) { data_ = data; }

    inline const QString& getName() const { return name_; }
    inline const str_map& getData() const { return data_; }


    friend QDataStream& operator<<(QDataStream& stream, const serialization& ser)
    {
        qInfo() << __PRETTY_FUNCTION__;

        stream << ser.name_;
        stream << ser.data_;

        return stream;
    }

    friend QDataStream& operator>>(QDataStream& stream, serialization& ser)
    {
        qInfo() << __PRETTY_FUNCTION__;

        stream >> ser.name_;
        stream >> ser.data_;

        return stream;
    }
private:

    QString name_;
    str_map data_;
};

