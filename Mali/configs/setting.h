#ifndef SETTING_H
#define SETTING_H

#include <QString>
#include <QSettings>



class Setting
{
    public:
        enum SettingKey {
            DBHostname,
            DBName,
            DBUser,
            DBPass
        };

        enum SettingStatus {
            Success = 0,
            ReadOnly = -1
        };

        static QString Load(const SettingKey &key);
        static SettingStatus Save(const SettingKey key, const QString &value);

        //static const QString *FILE_IS_READONLY;
    //protected:
        //static const QString SETTING_FILE;

    private:
        static void _loadFile();
        static QString _getKeyName(const SettingKey &key);
        static QScopedPointer<QSettings> *_sSetting;
};

#endif // SETTING_H
