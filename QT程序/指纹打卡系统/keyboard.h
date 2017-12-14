#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QString>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    QString messeage;
    ~Widget();

signals:
    void signalsforenter(QString);

private slots:
    void on_but_1_clicked();

    void on_but_2_clicked();

    void on_but_3_clicked();

    void on_but_4_clicked();

    void on_but_5_clicked();

    void on_but_6_clicked();

    void on_but_7_clicked();

    void on_but_8_clicked();

    void on_but_9_clicked();

    void on_but_0_clicked();

    void on_Q_but_Q_clicked();

    void on_Q_but_shift_clicked();

    void on_Q_but_BACK_clicked();

    void on_Q_but_W_clicked();

    void on_Q_but_E_clicked();

    void on_Q_but_R_clicked();

    void on_Q_but_T_clicked();

    void on_Q_but_Y_clicked();

    void on_Q_but_U_clicked();

    void on_Q_but_I_clicked();

    void on_Q_but_O_clicked();

    void on_Q_but_P_clicked();

    void on_Q_but_A_clicked();

    void on_Q_but_S_clicked();

    void on_Q_but_D_clicked();

    void on_Q_but_F_clicked();

    void on_Q_but_G_clicked();

    void on_Q_but_H_clicked();

    void on_Q_but_J_clicked();

    void on_Q_but_K_clicked();

    void on_Q_but_L_clicked();

    void on_Q_but_Z_clicked();

    void on_Q_but_X_clicked();

    void on_Q_but_C_clicked();

    void on_Q_but_V_clicked();

    void on_Q_but_B_clicked();

    void on_Q_but_N_clicked();

    void on_Q_but_M_clicked();

    void on_Q_but_douhao_clicked();

    void on_Q_but_juhao_clicked();

    void on_Q_but_ENTER_clicked();


private:
    Ui::Widget *ui; 
    bool shiftflag = false;
};

#endif // WIDGET_H
