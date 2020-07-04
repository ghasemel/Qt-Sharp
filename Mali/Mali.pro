#-------------------------------------------------
#
# Project created by QtCreator 2017-09-30T14:13:39
#
#-------------------------------------------------

QT       += core gui

CONFIG += c++11
# QMAKE_CXXFLAGS += -std=c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Mali
TEMPLATE = app
RC_FILE = myapp.rc


# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS


# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0



CONFIG(debug, debug|release) {
TARGET = Sharpd
DESTDIR = $$PWD/bin/debug/
} else {
TARGET = Sharp
DESTDIR = $$PWD/bin/release/
} # CONFIG(debug, debug|release)



SOURCES += \
        main.cpp \
        mainform.cpp \
        ./user/loginform.cpp \
        ./configs/theme.cpp \
        ./configs/setting.cpp \
    initconfigform.cpp \
    ./globals/globalstring.cpp \
    globals/constnumber.cpp \
    configs/formconfig.cpp \
    activationform.cpp


HEADERS += ./configs/theme.h \
    ./globals/globalstring.h \
    globals/constnumber.h \
    initconfigform.h \
    configs/formconfig.h \
    activationform.h
HEADERS += ./configs/setting.h

HEADERS += \
        mainform.h \
        ./user/loginform.h \




FORMS += \
        mainform.ui \
        ./user/loginform.ui \
    initconfigform.ui \
    activationform.ui


# add library here
#LIBS += -L"../Utils/bin"

#CONFIG(debug, debug|release) {
#LIBS += -l"QxOrmd"
#LIBS += -l"Utilsd"
#} else {
#LIBS += -l"QxOrm"
#LIBS += -l"Utils"
#} # CONFIG(debug, debug|release)

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/bin/release/ -lUtils
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/bin/debug/ -lUtilsd
else:unix: LIBS += -L$$PWD/bin/ -lUtils

CONFIG(debug, debug|release) {
INCLUDEPATH += $$PWD/bin/debug
DEPENDPATH += $$PWD/bin/debug
} else {
INCLUDEPATH += $$PWD/bin/release
DEPENDPATH += $$PWD/bin/release
} # CONFIG(debug, debug|release)



win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/bin/release/libUtils.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/bin/debug/libUtilsd.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/bin/release/Utils.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/bin/debug/Utilsd.lib
else:unix: PRE_TARGETDEPS += $$PWD/bin/libUtils.a

#win32:LIBS += -lIphlpapi

RESOURCES += \
    resource.qrc

DISTFILES += \
    myapp.rc
