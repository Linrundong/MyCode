#include "newpassword.h"
#include "ui_newpassword.h"


newpassword::newpassword(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newpassword)
{
    ui->setupUi(this);
    passwdeEdit = new MyLineEdit(this);
    passwdeEdit->setGeometry(105,207,661,21);
    keyboard = new Widget;

    connect(passwdeEdit,SIGNAL(editSignal()),this,SLOT(slotforedit()));
    connect(keyboard,SIGNAL(signalsforenter(QString)),this->passwdeEdit,SLOT(setText(QString)));
}

newpassword::~newpassword()
{
    delete ui;
}

void newpassword::slotforedit()
{
    keyboard->show();
}
