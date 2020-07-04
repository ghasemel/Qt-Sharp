#include "hardwareInfo.h"

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <intrin.h>
#include <iphlpapi.h>
#include <winnt.h>
#include <QString>
#include <QDebug>
#include <iostream>

#include "convert.h"



namespace Utils {

    hardwareInfo::hardwareInfo()
    {
        /*
        "00:05:69"; //vmware1
        "00:0C:29"; //vmware2
        "00:50:56"; //vmware3
        "00:1C:42"; //parallels1
        "00:03:FF"; //microsoft virtual pc
        "00:0F:4B"; //virtual iron 4
        "00:16:3E"; //red hat xen , oracle vm , xen source, novell xen
        "08:00:27"; //virtualbox
        */
        macVirtualAdapterList << "000569" << "000C29" << "005056" << "001C42"
                              << "0003FF" << "000F4B" << "00163E" << "080027";

    }

    /*
    // we just need this for purposes of unique machine id. So any one or two mac's is
    // fine.
    UINT16 hardwareInfo::hashMacAddress( PIP_ADAPTER_INFO info )
    {
        if (info == 0) {
            return 0;
        }

        UINT16 hash = 0;

        for ( UINT32 i = 0; i < info->AddressLength; i++ ) {
            qDebug() << UConvert::ConvertByteToHex(info->Address[i]);
            hash += ( info->Address[i] << (( i & 1 ) * 8 ));
        }
        return hash;
    }*/



    QString hardwareInfo::GetMacAddress()
    {
        IP_ADAPTER_INFO AdapterInfo[32];
        DWORD dwBufLen = sizeof( AdapterInfo );

        DWORD dwStatus = GetAdaptersInfo( AdapterInfo, &dwBufLen );
        if ( dwStatus != ERROR_SUCCESS )
            return NULL; // no adapters.

        PIP_ADAPTER_INFO pAdapterInfo = AdapterInfo;

        do {
            if (pAdapterInfo->AddressLength > 0 && pAdapterInfo->DhcpEnabled == 1 && (pAdapterInfo->Type == 6 || pAdapterInfo->Type == 71)) {
                qDebug() << pAdapterInfo->Description;

                QString mac = hardwareInfo::ConvertBytesToMACAddress(pAdapterInfo->Address);
                if (!IsVirtualAdapter(&mac))
                    return mac;
                    //UINT16 hashMac = hashMacAddress( pAdapterInfo );
            }
            pAdapterInfo = pAdapterInfo->Next;
        } while (pAdapterInfo);

        return NULL;
    }

    QString hardwareInfo::GetHddSerial()
    {
        DWORD disk_serialINT;
        GetVolumeInformationA(NULL, NULL, NULL, &disk_serialINT, NULL, NULL, NULL, NULL);

        return QString::number(disk_serialINT);
    }

    UINT32 hardwareInfo::GetCpuHash()
    {
        int cpuinfo[4] = { 0, 0, 0, 0 };
        __cpuid( cpuinfo, 0 );
        UINT32 hash = 0;
        UINT16* ptr = (UINT16*)(&cpuinfo[0]);
        for ( UINT32 i = 0; i < 8; i++ )
            hash += ptr[i];

        return hash;
    }

    const QString hardwareInfo::GetMachineName()
    {
        char computerName[1024];
        DWORD size = 1024;
        GetComputerName( LPWSTR(computerName), &size );

        QString str("");
        for (uint i = 0; i < size * 2; i+=2) {
            str += computerName[i];
        }
        return str; //&(computerName[0]);
    }

    bool hardwareInfo::IsVirtualAdapter(const QString *mac)
    {
        foreach (QString m, this->macVirtualAdapterList) {
            if (mac->startsWith(m))
                return true;
        }
        return false;
    }

    QString hardwareInfo::ConvertBytesToMACAddress(const unsigned char *bytes)
    {
        char buffer[13];
        buffer[12] = '0';
        for (int i = 0; i < 6; ++i) {
            std::sprintf(&buffer[i * 2], "%02X", bytes[i]);
        }
        return QString(buffer);
    }

    QString hardwareInfo::GenerateUnqiueId()
    {
        QString unique_id(GetMacAddress());
        if (unique_id == NULL) {
           //unique_id = GetCpuHash()
        }

        return unique_id;
    }
}

// Linux and OsX:
/*
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <sys/resource.h>
#include <sys/utsname.h>
#include <netdb.h>
#include <netinet/in.h>
#include <netinet/in_systm.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <assert.h>

#ifdef DARWIN
#include <net/if_dl.h>
#include <ifaddrs.h>
#include <net/if_types.h>
#else //!DARWIN
// #include <linux/if.h>
// #include <linux/sockios.h>
#endif //!DARWIN

const char* getMachineName()
{
   static struct utsname u;

   if ( uname( &u ) < 0 )
   {
      assert(0);
      return "unknown";
   }

   return u.nodename;
}


//---------------------------------get MAC addresses ------------------------------------unsigned short-unsigned short----------
// we just need this for purposes of unique machine id. So any one or two mac's is fine.
unsigned short hashMacAddress( unsigned char* mac )
{
   unsigned short hash = 0;

   for ( unsigned int i = 0; i < 6; i++ )
   {
      hash += ( mac[i] << (( i & 1 ) * 8 ));
   }
   return hash;
}

void getMacHash( unsigned short& mac1, unsigned short& mac2 )
{
   mac1 = 0;
   mac2 = 0;

#ifdef DARWIN

   struct ifaddrs* ifaphead;
   if ( getifaddrs( &ifaphead ) != 0 )
      return;

   // iterate over the net interfaces
   bool foundMac1 = false;
   struct ifaddrs* ifap;
   for ( ifap = ifaphead; ifap; ifap = ifap->ifa_next )
   {
      struct sockaddr_dl* sdl = (struct sockaddr_dl*)ifap->ifa_addr;
      if ( sdl && ( sdl->sdl_family == AF_LINK ) && ( sdl->sdl_type == IFT_ETHER ))
      {
          if ( !foundMac1 )
          {
             foundMac1 = true;
             mac1 = hashMacAddress( (unsigned char*)(LLADDR(sdl))); //sdl->sdl_data) + sdl->sdl_nlen) );
          } else {
             mac2 = hashMacAddress( (unsigned char*)(LLADDR(sdl))); //sdl->sdl_data) + sdl->sdl_nlen) );
             break;
          }
      }
   }

   freeifaddrs( ifaphead );

#else // !DARWIN

   int sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_IP );
   if ( sock < 0 ) return;

   // enumerate all IP addresses of the system
   struct ifconf conf;
   char ifconfbuf[ 128 * sizeof(struct ifreq)  ];
   memset( ifconfbuf, 0, sizeof( ifconfbuf ));
   conf.ifc_buf = ifconfbuf;
   conf.ifc_len = sizeof( ifconfbuf );
   if ( ioctl( sock, SIOCGIFCONF, &conf ))
   {
      assert(0);
      return;
   }

   // get MAC address
   bool foundMac1 = false;
   struct ifreq* ifr;
   for ( ifr = conf.ifc_req; (char*)ifr < (char*)conf.ifc_req + conf.ifc_len; ifr++ )
   {
      if ( ifr->ifr_addr.sa_data == (ifr+1)->ifr_addr.sa_data )
         continue;  // duplicate, skip it

      if ( ioctl( sock, SIOCGIFFLAGS, ifr ))
         continue;  // failed to get flags, skip it
      if ( ioctl( sock, SIOCGIFHWADDR, ifr ) == 0 )
      {
         if ( !foundMac1 )
         {
            foundMac1 = true;
            mac1 = hashMacAddress( (unsigned char*)&(ifr->ifr_addr.sa_data));
         } else {
            mac2 = hashMacAddress( (unsigned char*)&(ifr->ifr_addr.sa_data));
            break;
         }
      }
   }

   close( sock );

#endif // !DARWIN

   // sort the mac addresses. We don't want to invalidate
   // both macs if they just change order.
   if ( mac1 > mac2 )
   {
      unsigned short tmp = mac2;
      mac2 = mac1;
      mac1 = tmp;
   }
}

unsigned short getVolumeHash()
{
   // we don't have a 'volume serial number' like on windows. Lets hash the system name instead.
   unsigned char* sysname = (unsigned char*)getMachineName();
   unsigned short hash = 0;

   for ( unsigned int i = 0; sysname[i]; i++ )
      hash += ( sysname[i] << (( i & 1 ) * 8 ));

   return hash;
}

#ifdef DARWIN
 #include <mach-o/arch.h>
 unsigned short getCpuHash()
 {
     const NXArchInfo* info = NXGetLocalArchInfo();
     unsigned short val = 0;
     val += (unsigned short)info->cputype;
     val += (unsigned short)info->cpusubtype;
     return val;
 }

#else // !DARWIN

 static void getCpuid( unsigned int* p, unsigned int ax )
 {
    __asm __volatile
    (   "movl %%ebx, %%esi\n\t"
        "cpuid\n\t"
        "xchgl %%ebx, %%esi"
        : "=a" (p[0]), "=S" (p[1]),
          "=c" (p[2]), "=d" (p[3])
        : "0" (ax)
    );
 }

 unsigned short getCpuHash()
 {
    unsigned int cpuinfo[4] = { 0, 0, 0, 0 };
    getCpuid( cpuinfo, 0 );
    unsigned short hash = 0;
    unsigned int* ptr = (&cpuinfo[0]);
    for ( unsigned int i = 0; i < 4; i++ )
       hash += (ptr[i] & 0xFFFF) + ( ptr[i] >> 16 );

    return hash;
 }
#endif // !DARWIN

int main()
{

  printf("Machine: %s\n", getMachineName());
  printf("CPU: %d\n", getCpuHash());
  printf("Volume: %d\n", getVolumeHash());
  return 0;
}
*/
