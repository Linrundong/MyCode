#include "keywidget.h"
#include "ui_keywidget.h"

keywidget::keywidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::keywidget)
{
    ui->setupUi(this);
}

keywidget::~keywidget()
{
    delete ui;
}
