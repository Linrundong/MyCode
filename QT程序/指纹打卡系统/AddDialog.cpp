#include "AddDialog.h"
#include "ui_AddDialog.h"
#include <QMessageBox>


AddDialog::AddDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDialog)
{
    ui->setupUi(this);
    scheduleEdit = new MyLineEdit(this);
    scheduleEdit->setGeometry(113,57,669,30);

    keyboard = new Widget;

    connect(scheduleEdit,SIGNAL(editSignal()),this,SLOT(slotforedit()));
    connect(keyboard,SIGNAL(signalsforenter(QString)),this->scheduleEdit,SLOT(setText(QString)));
}

AddDialog::~AddDialog()
{
    delete ui;
    delete keyboard;
}


void AddDialog::on_okButton_clicked()
{
    QString tip = scheduleEdit->text();
    if(tip.isEmpty()) {
        QMessageBox::warning(this, tr("警告"), tr("计划名不能为空!"));
        return;
    }
    QTime time = ui->timeEdit->time();

    QTime startTime = ui->startEdit->time();
    if(startTime >= time) {
        QMessageBox::warning(this, tr("警告"), tr("最早打卡时间不得晚于指定打卡时间!"));
        return;
    }

    QTime endTime = ui->endEdit->time();

    if(endTime <= time) {
        QMessageBox::warning(this, tr("警告"), tr("最晚打卡时间不得早于指定打卡时间!"));
        return;
    }
    m_FingerBase.addSchedule(tip, time.toString(), startTime.toString(), endTime.toString(), ui->comboBox->currentIndex());
    addRecord();
    this->hide();

}

void AddDialog::on_backButton_clicked()
{
    this->hide();
}

void AddDialog::slotforedit()
{
    keyboard->show();
}
