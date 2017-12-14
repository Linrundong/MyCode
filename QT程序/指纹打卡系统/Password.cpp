#include "Password.h"
#include "ui_Password.h"
#include "SystemManager.h"

Password::Password(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Password), m_SystemManager(new SystemManager(this))
{
    ui->setupUi(this);
    ui->passwordEdit->setEchoMode(QLineEdit::Password);
    //m_SystemManager->show();
}

Password::~Password()
{
    delete ui;
}

void Password::on_enterButton_clicked()
{
    m_SystemManager->show();
}

void Password::on_passwordReturnButton_clicked()
{
    this->hide();
}


