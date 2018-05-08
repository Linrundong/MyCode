#include "startwidget.h"
#include "ui_startwidget.h"
#include <QPalette>
#include <QScrollArea>


startwidget::startwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::startwidget)
{
    ui->setupUi(this);
    w = new Widget;

    QPalette palette;
    QPixmap pixmap(":/new/prefix1/start.jpg");
    palette.setBrush(this->backgroundRole(), QBrush(pixmap));
    this->setPalette(palette);
}

startwidget::~startwidget()
{
    delete ui;
}

void startwidget::on_pushButton_clicked()
{
    w->show();
}
