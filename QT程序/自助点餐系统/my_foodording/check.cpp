#include "check.h"
#include "ui_check.h"
#include <QFont>
#include <QPixmap>

check::check(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::check)
{
    ui->setupUi(this);
}

void check::setprice(QString price)
{
    QFont font ("Microsoft YaHei", 20);
    ui->price->setFont(font);
    ui->price->setText(price);

}

check::~check()
{
    delete ui;
}

void check::on_pushButton_2_clicked()
{
    this->hide();
}

void check::on_pushButton_clicked()
{
    emit oversignal();
}
