#include "settings.h"
#include "QDebug"



void Settings::addData(const QString &key, const QVariant &value, const QString group)
{
    QPair<QString, QVariant> data {key, value};

    if(group.isEmpty())
    {
        addInfo(key, value);
    }
    else
    {
        data_[group].push_back(data);
    }
}

void Settings::addInfo(const QString &key, const QVariant &value, const QString group)
{
    bool addGroup {!group.isEmpty()};

    if(addGroup)
    {
        settings_.beginGroup(group);
    }

    settings_.setValue(key, value);
    qInfo() << settings_.fileName();
    qInfo() << settings_.status();


    if(addGroup)
    {
        settings_.endGroup();
    }

}


void Settings::readInfo()
{
    if(data_.empty())
    {
        qInfo() << "No groups added in settings \n";
        qInfo() << "Keys in settings: \n";

        foreach(const auto& key, settings_.allKeys())
        {
            qInfo() << key;
        }

        return;
    }

    foreach(const auto& group, data_.keys())
    {
        qInfo() << group << " contains \n";
        settings_.beginGroup(group);
        qInfo() << data_.value(group).toList();
        settings_.endGroup();
    }

    foreach(const auto& key, settings_.allKeys())
    {
        qInfo() << key;
    }
}
