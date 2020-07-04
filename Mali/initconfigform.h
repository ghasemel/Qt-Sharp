#ifndef INTICONFIGFORM_H
#define INTICONFIGFORM_H

#include <QDialog>

namespace Ui {
    class InitConfigForm;
}

class InitConfigForm : public QDialog
{
        Q_OBJECT

    public:
        explicit InitConfigForm(QWidget *parent = 0);
        ~InitConfigForm();

    private slots:
        void on_btnClose_clicked();

        void on_btnSave_clicked();

    private:
        Ui::InitConfigForm *ui;
        void showEvent(QShowEvent *ev);
};

#endif // INTICONFIGFORM_H
