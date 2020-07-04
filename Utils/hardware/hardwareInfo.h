#ifndef HARDWARE_H
#define HARDWARE_H


#include "../utils_global.h"
#include <windows.h>
#include <intrin.h>
#include <iphlpapi.h>

#include <QList>
#include <QString>

namespace Utils {
    class UTILSSHARED_EXPORT hardwareInfo
    {
        public:
            hardwareInfo();
            QString GetMacAddress();

            QString GetHddSerial();
            UINT32 GetCpuHash();
            const QString GetMachineName();
            bool IsVirtualAdapter(const QString *mac);
            QString ConvertBytesToMACAddress(const unsigned char *bytes);

            QString GenerateUnqiueId();

        private:

            /*
             virtual adapter mac address
            "00:05:69"; //vmware1
            "00:0C:29"; //vmware2
            "00:50:56"; //vmware3
            "00:1C:42"; //parallels1
            "00:03:FF"; //microsoft virtual pc
            "00:0F:4B"; //virtual iron 4
            "00:16:3E"; //red hat xen , oracle vm , xen source, novell xen
            "08:00:27"; //virtualbox
            */
            QList<QString> macVirtualAdapterList;

            //static UINT16 hashMacAddress( PIP_ADAPTER_INFO info );
    };    
}

typedef Utils::hardwareInfo UHardwareInfo;

#endif // HARDWARE_H
