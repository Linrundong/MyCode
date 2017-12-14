#include "serverwidget.h"
#include "ui_serverwidget.h"
#include <QDebug>
#include <QPixmap>
#include<QGraphicsOpacityEffect>
#include<QTextCursor>


/*
 #include <QtNetwork>
QTcpServer *server;
QTcpSocket *clientConnection;
server = new QTcpServer();
server->listen(QHostAddress::Any, 6665);
connect(server, SIGNAL(newConnection()), this, SLOT(acceptConnection()));
void acceptConnection()
{
    clientConnection = server->nextPendingConnection();
    connect(clientConnection, SIGNAL(readyRead()), this, SLOT(readClient()));
}
void readClient()
{
    QString str = clientConnection->readAll();
    //或者
    char buf[1024];
    clientConnection->read(buf,1024);
}
*/


void serverwidget::acceptConnection()
{
    clientConnection = server->nextPendingConnection();
    connect(clientConnection, SIGNAL(readyRead()), this, SLOT(readClient()));
}

void serverwidget::readClient()
{
    QString tmp = clientConnection->readAll();
    qDebug()<<tmp<<endl;
    //或者
    //char buf[1024];
    //clientConnection->read(buf,1024);

    QSqlQuery query;

    if(flag == 0)
        str += "\n--------------------------------\n";
    str += tmp;
    flag =0;


    this->ui->textEdit->setText(str);
    QFont font ("Microsoft YaHei", 20);
    ui->textEdit->setFont(font);

    //移动光标到文本末位
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.movePosition(QTextCursor::End);
    ui->textEdit->setTextCursor(cursor);

    this->sql_write(tmp);

}

serverwidget::serverwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::serverwidget)
{
    ui->setupUi(this);

    //this->setStyleSheet("border-image: url(:/new/prefix1/start.jpg)");
    QPixmap pixmap (":/new/prefix1/start.jpg");
    QPalette uu;
    uu.setBrush(QPalette::Window,QBrush(pixmap));
    this->setPalette(uu);

    //设置控件透明度
    QPalette pl = ui->textEdit->palette();
    pl.setBrush(QPalette::Base,QBrush(QColor(255,0,0,0)));
    ui->textEdit->setPalette(pl);

    QPalette P = ui->pushButton->palette();
    P.setColor(QPalette::Window,Qt::green);
    P.setBrush(QPalette::Window,Qt::blue);
    ui->pushButton->setPalette(P);
    ui->pushButton->setBackgroundRole(QPalette::Button);
    ui->pushButton->setAutoFillBackground(true);


    server = new QTcpServer();
    server->listen(QHostAddress::Any, 6665);
    connect(server, SIGNAL(newConnection()), this, SLOT(acceptConnection()));

    sqlwid = new sqlwidget(this);
    sqlwid->hide();
    connect(this->sqlwid,SIGNAL(showsqlwidget()),this,SLOT(slotforhide()));


    //创建与连接到数据库
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("T1.db");

    if(!db.open())
        qDebug()<<"open sqlite false"<<endl;

    QSqlQuery query;
    query.exec("drop table dishes");
    query.exec("create table dishes (id int primary key ,price varchar(10),content text)");

}

serverwidget::~serverwidget()
{
    delete ui;
}

void serverwidget::sql_write(QString str)
{
    //字符串操作，提取订单号、订单内容、消费金额
    int i=0;
    QString content;
    QString money;

    QString t1 = "号\n";
    QString t2 = "消费";
    int pos1 = str.indexOf(t1);
    int pos2 = str.indexOf(t2);

    for(i=pos1+2;i<str.length();i++)
    {
       if(str[i]=="消")
           break;
       content += str[i];
    }
    for(i=pos2+3;i<str.length();i++)
    {
       if(str[i]!="元")
           money += str[i];
    }
    content.remove("\n");

    //数据库插入数据
    QSqlQuery query;
    query.prepare("insert into dishes (id,price,content) values (:id, :num, :name)");
    query.bindValue(0, ++m_i);
    query.bindValue(1, money);
    query.bindValue(2, content);
    query.exec();

    query.exec("select * from dishes");
    while(query.next())
        qDebug()<<query.value(0).toInt()<<"\t"<<
                  query.value(1).toInt()<<"\t"<<
                  query.value(2).toString();
}

void serverwidget::on_pushButton_clicked()
{

    sqlwid->show();
    this->sqlwid->show_tableview(this->db);
}

void serverwidget::slotforhide()
{
    sqlwid->hide();
}
