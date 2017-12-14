#include "dishitem.h"
#include "ui_dishitem.h"

dishitem::dishitem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dishitem)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
}

dishitem::~dishitem()
{
    delete ui;
}

void dishitem::setDish(dish_s dish)
{
    this->dish = dish;
    ui->label_name->setText(dish.name); 
    ui->label_price->setText("价格："+QString::number(dish.price));
    QFont font ("Microsoft YaHei", 9);
    ui->label_name->setFont(font);
    ui->label_price->setFont(font);
    QString pic_path = dish.pic_name;
    ui->label_pic->setPixmap(QPixmap(pic_path));
}

void dishitem::on_pushButton_clicked()
{
    emit PopDish(this->dish);
}

void dishitem::on_pushButton_2_clicked()
{
    emit PushDish(this->dish);
}
