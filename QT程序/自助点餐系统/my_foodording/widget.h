#ifndef WIDGET_H
#define WIDGET_H

#include "dishitem.h"
#include "check.h"
#include "serial.h"

#include <QWidget>
#include <QString>
#include <QListView>
#include <QVector>
#include <QtNetwork>
#include <QPalette>
#include <QLayout>
#include <QDebug>
#include <QListWidget>
#include <QListWidgetItem>
#include <QList>
#include <QStandardItem>
#include <QMessageBox>
#include <sys/stat.h>
#include <QTextCodec>
#include <iostream>
#include <QMessageBox>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    serial * wifi_serial;
    void showdishitem();
    int m_i=1;

public slots:
    void show_allmessage(dish_s dish);
    void delete_message(dish_s dish);


private slots:
    void on_btn_end_clicked();
    void slotforover();


private:
    Ui::Widget *ui;
    int all_price;
    dishitem *widget1_1;
    dishitem *widget1_2;
    dishitem *widget1_3;
    dishitem *widget1_4;
    dishitem *widget1_5;
    dishitem *widget1_6;

    dishitem *widget2_1;
    dishitem *widget2_2;
    dishitem *widget2_3;

    dishitem *widget3_1;
    dishitem *widget3_2;
    dishitem *widget3_3;

    dishitem *widget4_1;
    dishitem *widget4_2;
    dishitem *widget4_3;

    QVector<QString> v_name;
    QVector<QString> v_name2;

    QVector<QString> allname = {"夏威夷比萨","超级至尊比萨","海鲜至尊比萨",
                                "田园风光比萨","新奥尔良比萨","北京潮鸭比萨",
                                "浓情烤翅","香草凤尾虾","鱼籽酱虾球",
                                "意式肉酱面","海鲜意面","黑椒牛柳意面",
                                "丝滑奶茶","红豆奶茶","鸡茸蘑菇汤" };
    QVector<int>     allnumber = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

    check * checkwidget;
};

#endif // WIDGET_H
