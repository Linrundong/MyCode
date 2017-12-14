#include "sqlwidget.h"
#include "ui_sqlwidget.h"
#include <QSqlQueryModel>
#include <QDebug>

sqlwidget::sqlwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::sqlwidget)
{
    ui->setupUi(this); 
}

sqlwidget::~sqlwidget()
{
    delete ui;
}

void sqlwidget::show_tableview(QSqlDatabase db)
{
    //连接到数据库
    //db = QSqlDatabase::addDatabase("QSQLITE");
    //db.setDatabaseName("T1.db");

    if(!db.open())
        qDebug()<<"open sqlite false"<<endl;

     static QSqlQueryModel *model = new QSqlQueryModel(ui->tableView);
     model->setQuery(QString("select * from dishes"));
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("单号"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("消费"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("详情"));
     //设置表头自动填充空白
     ui->tableView->horizontalHeader()->setStretchLastSection(true);
     //设置垂直表头不可见
     ui->tableView->verticalHeader()->setVisible(false);
     ui->tableView->setModel(model);
}

void sqlwidget::on_pushButton_clicked()
{
    emit showsqlwidget();
}
