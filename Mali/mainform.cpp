#include "mainform.h"
#include "ui_mainform.h"

#include "configs/theme.h"

MainForm::MainForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainForm)
{
    ui->setupUi(this);
    Theme::sSetFormTheme(this);
}

MainForm::~MainForm()
{
    delete ui;
}
