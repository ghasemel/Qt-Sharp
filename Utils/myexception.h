#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

#include <QException>

class MyException : QException
{
    public:
        MyException(const QString &data);
        void raise() const { throw *this; }
        MyException *clone() const { return new MyException(*this); }
};

#endif // MYEXCEPTION_H
