#include "form_util.h"
//#include <QDialog>



Form_Util::Form_Util(QWidget *parent) :
    QDialog(parent)
{

}

void Form_Util::show()
{
    this->setStyleSheet("font: bold 12pt \"B Mitra\";");
}
