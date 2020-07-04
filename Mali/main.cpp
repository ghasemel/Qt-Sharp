#include <QApplication>
#include <QDebug>

#include "mainform.h"
#include "user/loginform.h"
#include "../Utils/hardware/hardwareInfo.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    UHardwareInfo hw;

    qDebug() << "cpu: " << hw.GetCpuHash();
    qDebug() << "pc: " << hw.GetMachineName();
    qDebug() << "hdd: " << hw.GetHddSerial();
    qDebug() << "hdd: " << hw.GetMacAddress();


    LoginForm loginFrm;
    loginFrm.exec();

    //MainForm w;
    //w.showMaximized();


    //QString s("This is a test!");
    //qDebug() << s;

    return a.exec();
}
