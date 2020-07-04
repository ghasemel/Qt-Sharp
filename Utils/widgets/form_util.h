#ifndef FORM_UTIL_H
#define FORM_UTIL_H

#include <QDialog>

class Form_Util : public QDialog
{
        //Q_OBJECT

    public:
        explicit Form_Util(QWidget *parent = 0);
        void show();
};

#endif // FORM_UTIL_H
