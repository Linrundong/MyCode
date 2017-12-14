#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include <QEventLoop>
#include <QTimer>
#include <QPainter>
#include <QList>

// 手势的方向
enum GestureDirect
{
    LEFT = 0,   // 向左
    RIGHT = 1,  // 向右
    UP = 2,     // 向上
    DOWN = 3    // 向下
};

// 游戏部件类 继承自QWidget
class GameWidget : public QWidget
{
    Q_OBJECT
public:
    // 构造函数
    explicit GameWidget(QWidget *parent = 0);


private:
    /* 获取一个数字的二进制位数 当然这里获取的不完全是二进制位数 而是对应颜色数组的下标
    比如 2 对应 0    8 对应 2*/
    int getBitCount(int);
    // 小格子的宽度和高度
    qreal w, h;
    // 游戏面板 存储每个格子的数值
    int board[4][4];
    // 数码的个数 存储当前面板上的数字的个数
    int digitCount;

    // 绘制事件
    void paintEvent(QPaintEvent *);
    // 检测游戏是否结束
    bool checkGameOver();
    // 检测游戏是否获胜
    bool checkWin();

    // 起始点坐标 存储手势起点坐标
    QPoint startPos;
    // 鼠标按下触发的事件
    void mousePressEvent(QMouseEvent *);
    // 鼠标释放触发的事件
    void mouseReleaseEvent(QMouseEvent *);

signals:
    // 手势移动信号
    void GestureMove(GestureDirect);
    // 游戏结束信号
    void GameOver();
    // 游戏获胜信号
    void win();

public slots:
    // 处理手势移动信号的槽函数
    void onGestureMove(GestureDirect);
    // 重新开始的槽函数
    void restart();
};

#endif // GAMEWIDGET_H
