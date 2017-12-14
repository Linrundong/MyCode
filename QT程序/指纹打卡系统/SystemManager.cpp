#include "SystemManager.h"
#include "ui_SystemManager.h"

SystemManager::SystemManager(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SystemManager), m_AddSchedule(new AddSchedule(this))
{
    ui->setupUi(this);
    QImage background(":/Image/Background");
    QPalette palette;
    palette.setBrush(this->backgroundRole(),QBrush(background));
    this->setPalette(palette);

    newpasswd = new newpassword;
}

SystemManager::~SystemManager()
{
    delete ui;
}

void SystemManager::on_ScheduleButton_clicked()
{
    m_AddSchedule->show();
}

void SystemManager::on_manageReturnButton_clicked()
{
    this->hide();
}

void SystemManager::on_passwordButton_clicked()
{
    newpasswd->show();
}
