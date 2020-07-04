#include "loginform.h"
#include "ui_loginform.h"

#include "configs/theme.h"
#include "configs/setting.h"
#include "configs/formconfig.h"

#include "initconfigform.h"
#include "activationform.h"

#include <QDebug>
#include <QApplication>
#include <QMessageBox>

LoginForm::LoginForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginForm)
{
    ui->setupUi(this);
    Theme::sSetFormTheme(this);
    FormConfig::sConfigDialogTitleBar(this);
}

LoginForm::~LoginForm()
{
    delete ui;
}

void LoginForm::on_btnExit_clicked()
{
    QApplication::exit();
}

void LoginForm::on_btnLogin_clicked()
{

}

void LoginForm::on_btnConfig_clicked()
{
    InitConfigForm configFrm(this);
    configFrm.exec();
    ui->btnLogin->setEnabled(Setting::Load(Setting::DBHostname) != "");
}

void LoginForm::showEvent(QShowEvent *ev) {
    QDialog::showEvent(ev);
    ui->txtPass->setFocus();

    ui->btnLogin->setEnabled(Setting::Load(Setting::DBHostname) != "");
    if (!ui->btnLogin->isEnabled()) {
        LoginForm::on_btnConfig_clicked();
    }
}

void LoginForm::on_btnActivation_clicked()
{
    ActivationForm activationFrm(this);
    activationFrm.exec();
}
