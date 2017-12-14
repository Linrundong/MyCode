#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>
#include <QFile>
#include <QtGui>
#include "gamewidget.h"

// 主窗口部件类
class Widget : public QWidget
{
    Q_OBJECT

public:
    // 构造&析构函数
    Widget(QWidget *parent = 0);
    ~Widget();
private:
    // “restart”按钮
    QPushButton *restartBtn;
    QPushButton *closeBtn;
    // “score”标签
    QLabel *titleLabel;
    QLabel *tipsLabel;
    QLabel *scoreLbl;

    // 游戏部件
    GameWidget *gameWidget;

public slots:
    // 处理游戏结束信号的槽函数
    void onGameOver();
    // 处理游戏获胜信号的槽函数
    void onWin();
};

#endif // WIDGET_H
