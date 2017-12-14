#include "MainWin.h"
#include "ui_MainWin.h"
#include "FingerRecord.h"
#include "ArriveCheck.h"
#include "Password.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog), m_Record(new FingerRecord(this)), m_ArriveCheck(new ArriveCheck(this)), m_Password(new Password(this))
{
    ui->setupUi(this);
    //setWindowFlags (Qt::FramelessWindowHint);
    setBackground();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::setBackground() {
    QImage background(":/Image/Background");
    QPalette palette;
    palette.setBrush(this->backgroundRole(),QBrush(background));
    this->setPalette(palette);
}

void Dialog::on_fingerRecordButton_clicked()
{
    m_Record->show();
}

void Dialog::on_arriveCheckButton_clicked()
{
    m_ArriveCheck->show();
}

void Dialog::on_systemManagerButton_clicked()
{
    m_Password->show();
}
