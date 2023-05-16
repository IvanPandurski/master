#pragma once

#include <QSettings>

class Settings
{
    using data_map = QVector<QPair<QString, QVariant>>;
public:

//    Settings(const QString& orgName, const QString& appName) : settings_{orgName, appName} {}

    void addData(const QString& key, const QVariant& value, const QString group = "");
    void addInfo(const QString& key, const QVariant& value, const QString group = "");
    void readInfo();

    inline void sync() { settings_.sync(); }

    inline QSettings& get() { return settings_; }
private:
    QMap<QString, data_map> data_;
    QSettings settings_;
};
