#ifndef ACTIVATIONFORM_H
#define ACTIVATIONFORM_H

#include <QDialog>
#include <QMouseEvent>

namespace Ui {
    class ActivationForm;
}

class ActivationForm : public QDialog
{
        Q_OBJECT

    public:
        explicit ActivationForm(QWidget *parent = 0);
        ~ActivationForm();

    private:
        Ui::ActivationForm *ui;


        void mousePressEvent(QMouseEvent *event);
        void mouseMoveEvent(QMouseEvent *event);
        int m_nMouseClick_X_Coordinate;
        int m_nMouseClick_Y_Coordinate;
};

#endif // ACTIVATIONFORM_H
