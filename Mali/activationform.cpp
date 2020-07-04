#include "activationform.h"
#include "ui_activationform.h"

#include "configs/formconfig.h"
#include "configs/theme.h"

ActivationForm::ActivationForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ActivationForm)
{
    ui->setupUi(this);
    Theme::sSetFormTheme(this);
    FormConfig::sConfigDialogTitleBar(this);

    this->setWindowFlag(Qt::FramelessWindowHint, true);
    //this->setWindowFlags(Qt::Window | Qt::WindowStaysOnTopHint |
      //                   Qt::X11BypassWindowManagerHint | Qt::FramelessWindowHint);

    //this->setT
}

ActivationForm::~ActivationForm()
{
    delete ui;
}


void ActivationForm::mousePressEvent(QMouseEvent *event) {
    if (event->y() < 40) {
        m_nMouseClick_X_Coordinate = event->x();
        m_nMouseClick_Y_Coordinate = event->y();
    }
}

void ActivationForm::mouseMoveEvent(QMouseEvent *event) {
    if (event->y() < 40) {
        move(event->globalX()-m_nMouseClick_X_Coordinate,event->globalY()-m_nMouseClick_Y_Coordinate);
    }
}
