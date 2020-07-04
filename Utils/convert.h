#ifndef CONVERT_H
#define CONVERT_H

#include "utils_global.h"
#include <iostream>
#include <QString>

namespace Utils {
    class UTILSSHARED_EXPORT convert
    {
        public:
            inline static QString ConvertByteToHex(unsigned char byte)
            {
                // first method
                 char buffer[2];
                 std::sprintf(&buffer[0], "%02X", byte);
                 return QString(buffer);

                // second method
                // [][][][][][][][] - 8bits or one byte
                //int8_t buffer;
                //buffer = (byte >> 4) * 10;
               // buffer +=  byte & 15;
               // return QString::number(buffer);
            }


    };
}

typedef Utils::convert UConvert;

#endif // CONVERT_H
