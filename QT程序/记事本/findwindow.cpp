#include "findwindow.h"
#include "ui_findwindow.h"

findwindow::findwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::findwindow)
{
    ui->setupUi(this);
}

findwindow::~findwindow()
{
    delete ui;
}

void findwindow::on_pushButton_2_clicked()
{
    if(ui->fowardfind->isChecked())
        emit signalfind(ui->lineEdit->text());
    if(ui->backfind->isChecked())
        emit signalfind2(ui->lineEdit->text());
}

void findwindow::on_pushButton_clicked()
{
    close();
}
