#include "formconfig.h"



void FormConfig::sConfigDialogTitleBar(QWidget *dlg)
{
    dlg->setWindowFlag(Qt::WindowContextHelpButtonHint, false);
    //dlg->setWindowFlags(Qt::WindowSystemMenuHint | Qt::WindowTitleHint);
}
