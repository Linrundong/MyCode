#include "FingerRecord.h"
#include "ui_FingerRecord.h"
#include <QDebug>

FingerRecord::FingerRecord(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FingerRecord)
{
    ui->setupUi(this);
    setEditRule();
    initClassNum();

    keyboardforname = new Widget;
    keyboardforid = new Widget;

    nameedit = new MyLineEdit(this);
    nameedit->setGeometry(60,165,727,21);
    idedit = new MyLineEdit(this);
    idedit->setGeometry(60,200,727,21);
    connect(nameedit,SIGNAL(editSignal()),this,SLOT(slotfornameedit()));
    connect(idedit,SIGNAL(editSignal()),this,SLOT(slotforidedit()));
    connect(keyboardforname,SIGNAL(signalsforenter(QString)),this->nameedit,SLOT(setText(QString)));
    connect(keyboardforid,SIGNAL(signalsforenter(QString)),this->idedit,SLOT(setText(QString)));


}

FingerRecord::~FingerRecord()
{
    delete keyboardforname;
    delete keyboardforid;
    delete ui;
}

void FingerRecord::setEditRule() {
    QRegExp regExp("[0-9]{11}");
    QRegExpValidator *pRegExpValidator = new QRegExpValidator(regExp,this);
    //idedit->setValidator(pRegExpValidator);
}

void FingerRecord::initClassNum() {
    QVector<std::pair<int, QString>> tmp;
    m_FingerBase.getAllClass(tmp);
    for(auto& a : tmp) {
        ui->comboBox->addItem(a.second, a.first);
    }

}

void FingerRecord::registerFinger() {
    //获取用户信息并录入
}

void FingerRecord::on_buttonBox_accepted()
{
    //检查用户是否录入了三次
}

void FingerRecord::on_addStuButton_clicked()
{
    //向数据库添加学生信息
    m_FingerBase.addStudent(idedit->text(), nameedit->text(), ui->comboBox->itemData(ui->comboBox->currentIndex()).toInt());

    //准备录入指纹
}

void FingerRecord::slotfornameedit()
{
    keyboardforname->show();
}

void FingerRecord::slotforidedit()
{
    keyboardforid->show();
}
