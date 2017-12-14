#include "AddSchedule.h"
#include "ui_AddSchedule.h"

AddSchedule::AddSchedule(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddSchedule), m_AddDialog(new AddDialog(this))
{
    ui->setupUi(this);

    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setSelectionBehavior ( QAbstractItemView::SelectRows);
    ui->tableWidget->setRowCount(40);
    ui->tableWidget->setColumnCount(5);

    connect(m_AddDialog, SIGNAL(addRecord()), this, SLOT(setTableData()));
    setTableData();
}

AddSchedule::~AddSchedule()
{
    delete ui;
}

void AddSchedule::setTableData() {
    ui->tableWidget->clear();
    m_Data.clear();
    QStringList header;
    header.append("计划名");
    header.append("打卡时间");
    header.append("最早允许打卡时间");
    header.append("最晚运行打卡时间");
    header.append("标志");
    ui->tableWidget->setHorizontalHeaderLabels(header);

    m_FingerBase.getAllSchedule(m_Data);

    for(int i = 0; i < m_Data.size(); i++) {
        addRecord(i, m_Data[i].tip, m_Data[i].time, m_Data[i].start, m_Data[i].end, m_Data[i].flag == 0 ? "签到打卡" : "离开打卡");
    }

    ui->tableWidget->updateGeometry();

}

void AddSchedule::addRecord(int col, QString schName, QString time, QString start, QString end, QString flag) {
    ui->tableWidget->setItem(col, 0, new QTableWidgetItem(schName));
    ui->tableWidget->setItem(col, 1, new QTableWidgetItem(time));
    ui->tableWidget->setItem(col, 2, new QTableWidgetItem(start));
    ui->tableWidget->setItem(col, 3, new QTableWidgetItem(end));
    ui->tableWidget->setItem(col, 4, new QTableWidgetItem(flag));
}

void AddSchedule::on_deleteButton_clicked()
{
    int row = ui->tableWidget->currentRow();
    m_FingerBase.deleteSchedule(m_Data[row].id);
    setTableData();
}

void AddSchedule::on_addButton_clicked()
{
    m_AddDialog->show();
}

void AddSchedule::on_returnButton_clicked()
{
    this->hide();
}
