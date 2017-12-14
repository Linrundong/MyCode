#include "ArriveCheck.h"
#include "ui_ArriveCheck.h"
#include <QVector>
#include <utility>
#include <QStringList>

ArriveCheck::ArriveCheck(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ArriveCheck)
{
    ui->setupUi(this);
    initTerm();
}

void ArriveCheck::initTerm() {
    //初始化筛选框
    ui->nameBox->addItem("全部", 0);
    ui->classesBox->addItem("全部", 0);
    ui->dateBox->addItem("全部", 0);
    ui->filtrateBox->addItem("全部", 0);
    QVector<std::pair<int, QString>> tmp;
    m_FingerBase.getAllStudent(tmp);

    for(auto& a : tmp) {
        //qDebug() << a.second;
        ui->nameBox->addItem(a.second, a.first);
    }

    tmp.clear();

    m_FingerBase.getAllClass(tmp);
    for(auto & a : tmp) {
        ui->classesBox->addItem(a.second, a.first);
    }

    tmp.clear();

    m_FingerBase.getAllTime(tmp);
    for(auto & a : tmp) {
        ui->dateBox->addItem(a.second, a.first);
    }

    tmp.clear();

    m_FingerBase.getAllSchedule(tmp);
    for(auto & a : tmp) {
        ui->filtrateBox->addItem(a.second, a.first);
    }

    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setSelectionMode(QAbstractItemView::NoSelection);
    ui->tableWidget->setRowCount(40);
    //ui->tableWidget->setColumnCount(5);
    setTableData();
}

void ArriveCheck::addRecord(int col, QString stuNum, QString name, QString time, QString schedule, QString result) {
    ui->tableWidget->setItem(col, 0, new QTableWidgetItem(stuNum));
    ui->tableWidget->setItem(col, 1, new QTableWidgetItem(name));
    ui->tableWidget->setItem(col, 2, new QTableWidgetItem(time));
    ui->tableWidget->setItem(col, 3, new QTableWidgetItem(schedule));
    ui->tableWidget->setItem(col, 4, new QTableWidgetItem(result));
}

void ArriveCheck::setTableData() {
    ui->tableWidget->clear();
    QStringList header;
    header.append("学号");
    header.append("姓名");
    header.append("打卡时间");
    header.append("打卡类型");
    header.append("打卡情况");
    ui->tableWidget->setHorizontalHeaderLabels(header);

    int stuNumIndex = ui->nameBox->currentData().toInt();
    int classesIndex = ui->classesBox->currentData().toInt();
    QString dateIndex = ui->dateBox->currentText();
    int filtratIndex = ui->filtrateBox->currentData().toInt();

    QVector<Node> tmp;
    m_FingerBase.getAllRecord(tmp);

    int j = 0;
    for(int i = 0; i < tmp.size(); i++) {
        int index = ui->filtrateBox->findData(tmp[i].scheduleRef);
        if((tmp[i].id == stuNumIndex || stuNumIndex == 0) && (tmp[i].classRef == classesIndex || classesIndex == 0) &&
                (tmp[i].date == dateIndex || ui->dateBox->currentIndex() == 0) &&
                (tmp[i].scheduleRef == filtratIndex || filtratIndex == 0)) {
            schedule data;
            m_FingerBase.getScheduleById(tmp[i].scheduleRef, data);

            addRecord(j++, tmp[i].studentNum, tmp[i].name, tmp[i].date +" "+ tmp[i].time,
                      ui->filtrateBox->itemText(index), timeCmp(tmp[i].time, data.time, data.flag));
        }

    }
}

QString ArriveCheck::timeCmp(QString arriveTime, QString scheduleTime, int flag) {
    QTime arriveTimeTmp = QTime::fromString(arriveTime, "hh:mm:ss");
    QTime scheduleTimeTmp = QTime::fromString(scheduleTime, "hh:mm:ss");

    if(QTime(0,0,1) == arriveTimeTmp) {
        return "缺勤";
    }

    if(flag == 0) {
        return arriveTimeTmp <= scheduleTimeTmp ? "准时" : "迟到";
    }

    return arriveTimeTmp >= scheduleTimeTmp ? "早退" : "准时";

}

ArriveCheck::~ArriveCheck()
{
    delete ui;
}

void ArriveCheck::on_nameBox_currentIndexChanged(int index)
{
    setTableData();
}

void ArriveCheck::on_classesBox_currentIndexChanged(int index)
{
    setTableData();
}

void ArriveCheck::on_dateBox_currentIndexChanged(int index)
{
    setTableData();
}

void ArriveCheck::on_filtrateBox_currentIndexChanged(int index)
{
    setTableData();
}

void ArriveCheck::on_arriveReturnButton_clicked()
{
    this->hide();
}
