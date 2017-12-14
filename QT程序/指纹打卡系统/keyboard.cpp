#include "keyboard.h"
#include "ui_keyboard.h"
#include<QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->resize(800,470);
}

Widget::~Widget()
{
    delete ui;
}

/*ENTER回车键的槽*/
void Widget::on_Q_but_ENTER_clicked()
{
    qDebug()<<messeage<<endl;
    this->hide();
    emit signalsforenter(this->messeage);
}

/*大小写切换：shift*/
void Widget::on_Q_but_shift_clicked()
{
    shiftflag = !shiftflag;
    qDebug()<<"shift = "<<shiftflag<<endl;
}

/*删除键*/
void Widget::on_Q_but_BACK_clicked()
{
   messeage.chop(1);
   ui->textEdit->setText(messeage);
}

void Widget::on_but_1_clicked()
{
    messeage+="1";
    ui->textEdit->setText(messeage);
}

void Widget::on_but_2_clicked()
{
    messeage+="2";
    ui->textEdit->setText(messeage);
}

void Widget::on_but_3_clicked()
{
    messeage+="3";
    ui->textEdit->setText(messeage);
}

void Widget::on_but_4_clicked()
{
    messeage+="4";
    ui->textEdit->setText(messeage);
}

void Widget::on_but_5_clicked()
{
    messeage+="5";
    ui->textEdit->setText(messeage);
}

void Widget::on_but_6_clicked()
{
    messeage+="6";
    ui->textEdit->setText(messeage);
}

void Widget::on_but_7_clicked()
{
    messeage+="7";
    ui->textEdit->setText(messeage);
}

void Widget::on_but_8_clicked()
{
    messeage+="8";
    ui->textEdit->setText(messeage);
}

void Widget::on_but_9_clicked()
{
    messeage+="9";
    ui->textEdit->setText(messeage);
}

void Widget::on_but_0_clicked()
{
    messeage+="9";
    ui->textEdit->setText(messeage);
}

void Widget::on_Q_but_Q_clicked()
{
    if(shiftflag)
        messeage+="Q";
    else
        messeage+="q";
    ui->textEdit->setText(messeage);
}

void Widget::on_Q_but_W_clicked()
{
    if(shiftflag)
        messeage+="W";
    else
        messeage+="w";
    ui->textEdit->setText(messeage);
}

void Widget::on_Q_but_E_clicked()
{
    if(shiftflag)
        messeage+="E";
    else
        messeage+="e";
    ui->textEdit->setText(messeage);
}

void Widget::on_Q_but_R_clicked()
{
    if(shiftflag)
        messeage+="R";
    else
        messeage+="r";
    ui->textEdit->setText(messeage);
}

void Widget::on_Q_but_T_clicked()
{
    if(shiftflag)
        messeage+="T";
    else
        messeage+="t";
    ui->textEdit->setText(messeage);
}

void Widget::on_Q_but_Y_clicked()
{
    if(shiftflag)
        messeage+="Y";
    else
        messeage+="y";
    ui->textEdit->setText(messeage);
}

void Widget::on_Q_but_U_clicked()
{
    if(shiftflag)
        messeage+="U";
    else
        messeage+="u";
    ui->textEdit->setText(messeage);
}

void Widget::on_Q_but_I_clicked()
{
    if(shiftflag)
        messeage+="I";
    else
        messeage+="i";
    ui->textEdit->setText(messeage);
}

void Widget::on_Q_but_O_clicked()
{
    if(shiftflag)
        messeage+="O";
    else
        messeage+="o";
    ui->textEdit->setText(messeage);
}

void Widget::on_Q_but_P_clicked()
{
    if(shiftflag)
        messeage+="P";
    else
        messeage+="p";
    ui->textEdit->setText(messeage);
}

void Widget::on_Q_but_A_clicked()
{
    if(shiftflag)
        messeage+="A";
    else
        messeage+="a";
    ui->textEdit->setText(messeage);
}

void Widget::on_Q_but_S_clicked()
{
    if(shiftflag)
        messeage+="S";
    else
        messeage+="s";
    ui->textEdit->setText(messeage);
}

void Widget::on_Q_but_D_clicked()
{
    if(shiftflag)
        messeage+="D";
    else
        messeage+="d";
    ui->textEdit->setText(messeage);
}

void Widget::on_Q_but_F_clicked()
{
    if(shiftflag)
        messeage+="F";
    else
        messeage+="f";
    ui->textEdit->setText(messeage);
}

void Widget::on_Q_but_G_clicked()
{
    if(shiftflag)
        messeage+="G";
    else
        messeage+="g";
    ui->textEdit->setText(messeage);
}

void Widget::on_Q_but_H_clicked()
{
    if(shiftflag)
        messeage+="H";
    else
        messeage+="h";
    ui->textEdit->setText(messeage);
}

void Widget::on_Q_but_J_clicked()
{
    if(shiftflag)
        messeage+="J";
    else
        messeage+="j";
    ui->textEdit->setText(messeage);
}

void Widget::on_Q_but_K_clicked()
{
    if(shiftflag)
        messeage+="K";
    else
        messeage+="k";
    ui->textEdit->setText(messeage);
}

void Widget::on_Q_but_L_clicked()
{
    if(shiftflag)
        messeage+="L";
    else
        messeage+="l";
    ui->textEdit->setText(messeage);
}

void Widget::on_Q_but_Z_clicked()
{
    if(shiftflag)
        messeage+="Z";
    else
        messeage+="z";
    ui->textEdit->setText(messeage);
}

void Widget::on_Q_but_X_clicked()
{
    if(shiftflag)
        messeage+="X";
    else
        messeage+="x";
    ui->textEdit->setText(messeage);
}

void Widget::on_Q_but_C_clicked()
{
    if(shiftflag)
        messeage+="C";
    else
        messeage+="c";
    ui->textEdit->setText(messeage);
}

void Widget::on_Q_but_V_clicked()
{
    if(shiftflag)
        messeage+="V";
    else
        messeage+="v";
    ui->textEdit->setText(messeage);
}

void Widget::on_Q_but_B_clicked()
{
    if(shiftflag)
        messeage+="B";
    else
        messeage+="b";
    ui->textEdit->setText(messeage);
}

void Widget::on_Q_but_N_clicked()
{
    if(shiftflag)
        messeage+="N";
    else
        messeage+="n";
    ui->textEdit->setText(messeage);
}

void Widget::on_Q_but_M_clicked()
{
    if(shiftflag)
        messeage+="M";
    else
        messeage+="m";
    ui->textEdit->setText(messeage);
}

void Widget::on_Q_but_douhao_clicked()
{
    messeage+=",";//英文逗号
    ui->textEdit->setText(messeage);
}

void Widget::on_Q_but_juhao_clicked()
{
    messeage+=".";//英文句号
    ui->textEdit->setText(messeage);
}


