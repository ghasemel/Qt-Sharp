#ifndef LOGINFORM_H
#define LOGINFORM_H

#include <QDialog>
#include "../Utils/widgets/form_util.h"

namespace Ui {
    class LoginForm;
}

class LoginForm : public QDialog
{
        Q_OBJECT

    public:
        explicit LoginForm(QWidget *parent = 0);
        ~LoginForm();

    private slots:
        void on_btnExit_clicked();

        void on_btnLogin_clicked();

        void on_btnConfig_clicked();

        void on_btnActivation_clicked();

    private:
        Ui::LoginForm *ui;
        void showEvent(QShowEvent *ev);
};

#endif // LOGINFORM_H
