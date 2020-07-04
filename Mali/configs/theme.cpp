#include "theme.h"
#include <QString>
#include <QLocale>

//const QString Theme::FORM_STYLE = "font: bold 12pt \"B Mitra\";\n";



void Theme::sSetFormTheme(QWidget *form)
{
    //form->setStyleSheet("font: 12pt \"B Nazanin\";\n");
    form->setStyleSheet("font: 10pt \"B Tahoma\";\n");
    form->setLayoutDirection(Qt::RightToLeft);
    form->setLocale(QLocale(QLocale::Persian, QLocale::Iran));
}
