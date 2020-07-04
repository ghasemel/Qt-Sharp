#include "setting.h"
#include <QApplication>
#include <QSettings>
#include <QDebug>
#include <QFileInfo>
#include <QException>

//const QString Setting::SETTING_FILE = QApplication::applicationDirPath() + "/setting.ini";
QScopedPointer<QSettings> *Setting::_sSetting = nullptr;
//const QString *Setting::FILE_IS_READONLY = QString("readonly");

void Setting::_loadFile()
{
    if (Setting::_sSetting == nullptr)
        Setting::_sSetting = new QScopedPointer<QSettings>(new QSettings(QApplication::applicationDirPath() + "/setting.ini", QSettings::IniFormat));
}



QString Setting::Load(const Setting::SettingKey &key)
{
    _loadFile();
    if (_sSetting->data()->status() == QSettings::NoError)
        return _sSetting->data()->value(_getKeyName(key)).toString();
    return nullptr;
}

Setting::SettingStatus Setting::Save(const Setting::SettingKey key, const QString &value)
{
    _loadFile();

    if (!_sSetting->data()->isWritable())
        return Setting::ReadOnly;
        //throw(QString(Setting::FILE_IS_READONLY));

    _sSetting->data()->setValue(_getKeyName(key), value);
    _sSetting->data()->sync();

    return Setting::Success;
}



QString Setting::_getKeyName(const Setting::SettingKey &key) {
    switch (key) {
        case Setting::DBHostname: return "DBHostname";
        case Setting::DBName: return "DBName";
        case Setting::DBUser: return "DBUser";
        case Setting::DBPass: return "DBPass";
        default: return "";
    }
}
