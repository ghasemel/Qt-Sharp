#include "initconfigform.h"
#include "ui_initconfigform.h"

#include "configs/theme.h"
#include "globals/globalstring.h"
#include "configs/setting.h"
#include "configs/formconfig.h"

#include <QMessageBox>

InitConfigForm::InitConfigForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InitConfigForm)
{
    ui->setupUi(this);
    Theme::sSetFormTheme(this);
    FormConfig::sConfigDialogTitleBar(this);
}

InitConfigForm::~InitConfigForm()
{
    delete ui;
}

void InitConfigForm::on_btnClose_clicked()
{
    this->reject();
}

void InitConfigForm::on_btnSave_clicked()
{
    if (ui->txtHost->text() == "") {
        QMessageBox::warning(this, globalString::TITLE_ERROR_IN_DATA_ENTERANCE, "آدرس سرور دیتابیس نمی تواند خالی باشد", globalString::OK_BUTTON);
        ui->txtHost->setFocus();
        return;
    }

    if (ui->txtUser->text() == "") {
        QMessageBox::warning(this, globalString::TITLE_ERROR_IN_DATA_ENTERANCE, "نام کاربری دیتابیس نمی تواند خالی باشد", globalString::OK_BUTTON);
        return;
    }

    if (ui->txtPass->text() == "") {
        QMessageBox::warning(this, globalString::TITLE_ERROR_IN_DATA_ENTERANCE, "پسورد دیتابیس نمی تواند خالی باشد", globalString::OK_BUTTON);
        return;
    }

    if (Setting::Save(Setting::DBHostname, ui->txtHost->text()) == Setting::ReadOnly) {
        QMessageBox::critical(this, "خطا در ذخیرسازی", "فایل تنظیمات قابل نوشتن نیست. لطفا به محل نصب نرم افزار رفته و فایل را بررسی کنید.", globalString::OK_BUTTON);
        return;
    }

    if (Setting::Save(Setting::DBUser, ui->txtUser->text()) == Setting::ReadOnly) {
        QMessageBox::critical(this, "خطا در ذخیرسازی", "فایل تنظیمات قابل نوشتن نیست. لطفا به محل نصب نرم افزار رفته و فایل را بررسی کنید.", globalString::OK_BUTTON);
        return;
    }

    if (Setting::Save(Setting::DBPass, ui->txtPass->text()) == Setting::ReadOnly) {
        QMessageBox::critical(this, "خطا در ذخیرسازی", "فایل تنظیمات قابل نوشتن نیست. لطفا به محل نصب نرم افزار رفته و فایل را بررسی کنید.", globalString::OK_BUTTON);
        return;
    }

    this->accept();
}


void InitConfigForm::showEvent(QShowEvent *ev) {
    QDialog::showEvent(ev);

    ui->txtHost->setText(Setting::Load(Setting::DBHostname));
    ui->txtUser->setText(Setting::Load(Setting::DBUser));
    ui->txtPass->setText(Setting::Load(Setting::DBPass));
}
