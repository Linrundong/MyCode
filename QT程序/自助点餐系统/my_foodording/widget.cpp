#include "widget.h"
#include "ui_widget.h"
#include <QPalette>
#include <QLayout>
#include <QDebug>
#include <QListWidget>
#include <QListWidgetItem>
#include <QVector>
#include <QList>
#include<QStandardItem>
#include <QMessageBox>
#include <sys/stat.h>
#include <QTextCodec>
#include<iostream>
#include <QMessageBox>

/*
#include <QtNetwork>
QTcpSocket *client;
char *data="hello qt!";
client = new QTcpSocket(this);
client->connectToHost(QHostAddress("10.21.11.66"), 6665);
client->write(data)
*/

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->all_price=0;

    //背景
    QPalette palette;
    QPixmap pixmap(":/new/prefix1/back.gif");
    palette.setBrush(QPalette::Background, QBrush(pixmap));
    this->setPalette(palette);

    widget1_1 = new dishitem;
    widget1_2 = new dishitem;
    widget1_3 = new dishitem;
    widget1_4 = new dishitem;
    widget1_5 = new dishitem;
    widget1_6 = new dishitem;

    widget2_1 = new dishitem;
    widget2_2 = new dishitem;
    widget2_3 = new dishitem;

    widget3_1 = new dishitem;
    widget3_2 = new dishitem;
    widget3_3 = new dishitem;

    widget4_1 = new dishitem;
    widget4_2 = new dishitem;
    widget4_3 = new dishitem;

    checkwidget = new check;
    connect(checkwidget,SIGNAL(oversignal()),this,SLOT(slotforover()));

    showdishitem();

    ui->chose_menu->setViewMode(QListView::ListMode);

    //网络连接
    client = new QTcpSocket(this);
    client->connectToHost(QHostAddress("192.168.1.166"), 6665);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::showdishitem()
{
    /****主食页面*******************************/
    QVector<QString> v_name_page1 = {"夏威夷比萨","超级至尊比萨","海鲜至尊比萨",
                                    "田园风光比萨","新奥尔良比萨","北京潮鸭比萨"};
    QVector<int> v_price_page1 = {100,120,199,90,80,150};
    QVector<QString> v_pic_page1 = {":/new/prefix1/dishitem_pic/1-1.jpg",
                                    ":/new/prefix1/dishitem_pic/1-2.jpg",
                                    ":/new/prefix1/dishitem_pic/1-3.jpg",
                                    ":/new/prefix1/dishitem_pic/1-4.jpg",
                                    ":/new/prefix1/dishitem_pic/1-5.jpg",
                                    ":/new/prefix1/dishitem_pic/1-6.jpg"};
    QVector<dishitem*> v_widget_page1 = {widget1_1,widget1_2,widget1_3,
                                        widget1_4,widget1_5,widget1_6};


    for(int i=0;i<6;i++)
    {
        int j=0,k;
        k=i;
        if(i>=3)
        {
            k=i-3;
            j=1;
        }
        v_widget_page1[i]->dish.id=1;
        v_widget_page1[i]->dish.name = v_name_page1[i];
        v_widget_page1[i]->dish.pic_name=v_pic_page1[i];
        v_widget_page1[i]->dish.price = v_price_page1[i];
        v_widget_page1[i]->setDish(v_widget_page1[i]->dish);
        this->ui->Layout_mainfood_->addWidget(v_widget_page1[i],j,k,1,1);
        connect(v_widget_page1[i],SIGNAL(PopDish(dish_s)),this,SLOT(show_allmessage(dish_s)));
        connect(v_widget_page1[i],SIGNAL(PushDish(dish_s)),this,SLOT(delete_message(dish_s)));
    }

  /****小食页面*******************************/
    QVector<QString> v_name_page2 = {"浓情烤翅","香草凤尾虾","鱼籽酱虾球"};
    QVector<int> v_price_page2 = {60,70,50};
    QVector<QString> v_pic_page2 = {":/new/prefix1/dishitem_pic/2-1.jpg",
                               ":/new/prefix1/dishitem_pic/2-2.jpg",
                               ":/new/prefix1/dishitem_pic/2-3.jpg"};
    QVector<dishitem*> v_widget_page2 = {widget2_1,widget2_2,widget2_3};

    for(int i=0;i<3;i++)
    {
        v_widget_page2[i]->dish.id=1;
        v_widget_page2[i]->dish.name = v_name_page2[i];
        v_widget_page2[i]->dish.pic_name=v_pic_page2[i];
        v_widget_page2[i]->dish.price = v_price_page2[i];
        v_widget_page2[i]->setDish(v_widget_page2[i]->dish);
        this->ui->Layout_minorfood_->addWidget(v_widget_page2[i],0,i,1,1);
        connect(v_widget_page2[i],SIGNAL(PopDish(dish_s)),this,SLOT(show_allmessage(dish_s)));
        connect(v_widget_page2[i],SIGNAL(PushDish(dish_s)),this,SLOT(delete_message(dish_s)));
    }

    /***意面页面*******************************/
      QVector<QString> v_name_page3 = {"意式肉酱面","海鲜意面","黑椒牛柳意面"};
      QVector<int> v_price_page3 = {40,30,35};
      QVector<QString> v_pic_page3= {":/new/prefix1/dishitem_pic/4-1.jpg",
                                 ":/new/prefix1/dishitem_pic/4-2.jpg",
                                    ":/new/prefix1/dishitem_pic/4-1.jpg"};
      QVector<dishitem*> v_widget_page3 = {widget4_1,widget4_2,widget4_3};

      for(int i=0;i<3;i++)
      {
          v_widget_page3[i]->dish.id=1;
          v_widget_page3[i]->dish.name = v_name_page3[i];
          v_widget_page3[i]->dish.pic_name=v_pic_page3[i];
          v_widget_page3[i]->dish.price = v_price_page3[i];

          v_widget_page3[i]->setDish(v_widget_page3[i]->dish);
          this->ui->Layout_sweet->addWidget(v_widget_page3[i],0,i,1,1);
          connect(v_widget_page3[i],SIGNAL(PopDish(dish_s)),this,SLOT(show_allmessage(dish_s)));
          connect(v_widget_page3[i],SIGNAL(PushDish(dish_s)),this,SLOT(delete_message(dish_s)));
      }

    /****饮料页面*******************************/
      QVector<QString> v_name_page4 = {"丝滑奶茶","红豆奶茶","鸡茸蘑菇汤"};
      QVector<int> v_price_page4 = {22,20,30};
      QVector<QString> v_pic_page4= {":/new/prefix1/dishitem_pic/3-1.jpg",
                                 ":/new/prefix1/dishitem_pic/3-2.jpg",
                                 ":/new/prefix1/dishitem_pic/3-3.jpg"};
      QVector<dishitem*> v_widget_page4 = {widget3_1,widget3_2,widget3_3};

      for(int i=0;i<3;i++)
      {
          v_widget_page4[i]->dish.id=1;
          v_widget_page4[i]->dish.name = v_name_page4[i];
          v_widget_page4[i]->dish.pic_name=v_pic_page4[i];
          v_widget_page4[i]->dish.price = v_price_page4[i];

          v_widget_page4[i]->setDish(v_widget_page4[i]->dish);
          this->ui->Layout_drink_->addWidget(v_widget_page4[i],0,i,1,1);
          connect(v_widget_page4[i],SIGNAL(PopDish(dish_s)),this,SLOT(show_allmessage(dish_s)));
          connect(v_widget_page4[i],SIGNAL(PushDish(dish_s)),this,SLOT(delete_message(dish_s)));
      }

}

void Widget::show_allmessage(dish_s dish)
{
    this->all_price += dish.price;
    QString s = QString::number(this->all_price, 10);
    this->ui->label_price->setText("金额："+s);

    ui->chose_menu->clear();
    for(int i=0;i<allname.length();i++)
    {
        if(allname[i] == dish.name)
        {
            allnumber[i]++;
        }

        if(allnumber[i]>0)
        {
            QString str = allname[i];
            QListWidgetItem *item = new QListWidgetItem;
            item->setText(str + " * " + QString::number(allnumber[i], 10));
            this->ui->chose_menu->addItem(item);
        }
    }

    QFont font ("Microsoft YaHei", 10);
    this->ui->chose_menu->setFont(font);
    //qDebug()<<allname<<endl;
    //qDebug()<<allnumber<<endl;
}

void Widget::delete_message(dish_s dish)
{
    ui->chose_menu->clear();
    for(int i=0;i<allname.length();i++)
    {
        if(allname[i] == dish.name)
        {
            if(allnumber[i]>0)
            {
                allnumber[i]--;
                this->all_price-=dish.price;
            }
        }

        if(allnumber[i]>0)
        {
            QString str = allname[i];
            QListWidgetItem *item = new QListWidgetItem;
            item->setText(str + " * " + QString::number(allnumber[i], 10));
            this->ui->chose_menu->addItem(item);

        }
    }

    QFont font ("Microsoft YaHei", 10);
    this->ui->chose_menu->setFont(font);

    QString s = QString::number(this->all_price, 10);
    this->ui->label_price->setText("金额："+s);

    //qDebug()<<allname<<endl;
    //qDebug()<<allnumber<<endl;
}


void Widget::on_btn_end_clicked()
{
    if(this->all_price>0)
    {
        this->checkwidget->show();
        QString tmp = "总金额："+ QString::number(this->all_price);
        this->checkwidget->setprice(tmp);
    }
    else
    {
        QMessageBox::warning(NULL, "注意", "您未点单");
    }

}

void Widget::slotforover()
{
    this->checkwidget->hide();
    this->hide();

    //转换数据
    QString tmp;
    tmp += ("点单号：" + QString::number(this->m_i) + "号" + "\n");
    this->m_i++;
    QVector<QString>::iterator it1 =this->allname.begin();
    QVector<int>::iterator it2 =this->allnumber.begin();
    for(int i=0;i<15;i++)
    {
        if(*it2>0)
        {
            tmp += *it1;
            it1++;
            tmp += " * ";
            tmp += QString::number(*it2);
            it2++;
            tmp += "  \n";
        }
        else
        {
            it2++;
            it1++;
        }
    }
    tmp += ("消费：" + QString::number(this->all_price) + "元");

    //QByteArray ba = tmp.toLatin1();
    std::string tmp2 = tmp.toStdString();
    const char * str = tmp2.c_str();
    qDebug()<<str<<endl;

    //发送数据
    client->write(str);
    //client->write(ba);

    //初始化
    this->ui->chose_menu->clear();
    this->all_price=0;
    this->allnumber={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
}


