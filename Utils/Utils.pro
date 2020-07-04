#-------------------------------------------------
#
# Project created by QtCreator 2017-09-29T19:37:28
#
#-------------------------------------------------

QT       += widgets network sql script xml

greaterThan(QT_MAJOR_VERSION, 4): QT += printsupport

TARGET = Utils
TEMPLATE = lib

DEFINES += UTILS_LIBRARY

CONFIG(debug, debug|release) {
TARGET = Utilsd
DESTDIR = $$PWD/../Mali/bin/debug/
} else {
TARGET = Utils
DESTDIR = $$PWD/../Mali/bin/release/
} # CONFIG(debug, debug|release)

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += utils.cpp \
    widgets/form_util.cpp \
    string_util.cpp \
    myexception.cpp \
    ./hardware/hardwareInfo.cpp \
    convert.cpp

HEADERS += utils.h \
    widgets/form_util.h \
    string_util.h \
    myexception.h \
    ./hardware/hardwareInfo.h \
    convert.h
HEADERS += utils_global.h


unix {
    target.path = /usr/lib
    INSTALLS += target
}



win32:LIBS += -lIphlpapi
