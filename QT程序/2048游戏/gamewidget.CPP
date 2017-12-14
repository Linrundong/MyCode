#include <QDebug>
#include "GameWidget.h"

//颜色数组
QColor digitBkg[11] = {QColor::fromRgb(0xEE, 0xE5, 0xDB), QColor::fromRgb(0xEC, 0xE0, 0xC8),
                            QColor::fromRgb(0xF2, 0xAF, 0x78), QColor::fromRgb(0xEE, 0x8A, 0x54),
                            QColor::fromRgb(0xFE, 0x76, 0x5E), QColor::fromRgb(0xE7, 0x58, 0xC),
                            QColor::fromRgb(0xFF, 0x66, 0x66), QColor::fromRgb(0xF1, 0xCF, 0x48),
                            QColor::fromRgb(0xCC, 0x33, 0x33), QColor::fromRgb(0xE3, 0xB9, 0x11),
                            QColor::fromRgb(0xFF, 0x00, 0x00)};

GameWidget::GameWidget(QWidget *parent) :
    QWidget(parent)
{
    // 连接手势移动信号和相应的槽函数
    connect(this, SIGNAL(GestureMove(GestureDirect)), SLOT(onGestureMove(GestureDirect)));
    // 初始化board数组
    memset(board, 0, sizeof(board));
    // 随机填入两个2
    board[rand() % 4][rand() % 4] = 2;
    while(true) {
        int x = rand() % 4;
        int y = rand() % 4;
        if (board[x][y] != 0) {
            continue;
        }
        else {
            board[x][y] = 2;
            break;
        }
    }
    // 数码个数初始化为2
    digitCount = 2;
}

//绘图事件
void GameWidget::paintEvent(QPaintEvent *)
{
    // 构造一个QPainter对象 使用它来进行绘图
    QPainter painter(this);


    // 构造一个画刷 颜色为R G B分量分别为141 121 81的颜色
    QBrush brush(QColor::fromRgb(141, 121, 81));
    // 使painter应用这个画刷
    painter.setBrush(brush);

    // 设置画笔为空笔 目的是使绘制的图形没有描边
    painter.setPen(Qt::NoPen);

    // 绘制一个没有描边的矩形(小格子背景）
    painter.drawRect(2, 2, width() - 4, height() - 4);

    // 计算每个小格子的宽度和高度，小格子间距为5
    w = width() - 4, h = height() - 4;
    w = (w - 25) / 4, h = (h - 25) / 4;

    /* 构造一个字体
     * 字体名字为Consolas
     * 字体设置为粗体
     * 字体大小为40像素
     * */
    QFont font;
    font.setFamily("Consolas");
    font.setBold(true);
    font.setPixelSize(40);
    // 使painter应用这个字体
    painter.setFont(font);

    // 循环绘制游戏面板
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
        {
            // 如果方格中有数字
            if (board[i][j])
            {
                // 设置画刷颜色为数字对应的颜色
                brush.setColor(digitBkg[getBitCount(board[i][j])]);
                // 应用这个画刷
                painter.setBrush(brush);
                // 绘制一个小方格
                painter.drawRect(QRectF(7 + (w + 5) * j, 7 + (h + 5) * i, w, h));
                // 设置画笔为黑色画笔
                painter.setPen(QColor::fromRgb(0, 0, 0));
                // 绘制数字
                painter.drawText(QRectF(7 + (w + 5) * j, 7 + (h + 5) * i, w, h), Qt::AlignCenter,
                                 QString::number(board[i][j]));
                // 设置画笔为空笔
                painter.setPen(Qt::NoPen);
            }
            // 如果方格中没有数字
            else
            {
                // 设置画刷颜色为 RGB分量为171 165 141的颜色
                brush.setColor(QColor::fromRgb(171, 165, 141));
                // 应用这个画刷
                painter.setBrush(brush);
                // 绘制小方格
                painter.drawRect(QRectF(7 + (w + 5) * j, 7 + (h + 5) * i, w, h));
            }
        }
}

int GameWidget::getBitCount(int n)
{
    // 循环获取数字二进制位数
    int c = 0;
    while (n >>= 1)
        c++;
    // 返回位数-1
    return c - 1;
}

//按下鼠标事件：
//QMouseEvent：鼠标事件发生当一个鼠标按键被按下或释放内部部件,或者是当鼠标光标移动。
void GameWidget::mousePressEvent(QMouseEvent *e)
{
    // 获取起点坐标
    startPos = e->pos();
    //qDebug()<<startPos;
}

//释放鼠标事件
void GameWidget::mouseReleaseEvent(QMouseEvent *e)
{
    // 根据终点坐标和起点坐标计算XY坐标的增量
    float dX = (float)(e->pos().x() - startPos.x());
    float dY = (float)(e->pos().y() - startPos.y());
    // 确定手势方向
    if (abs(dX) > abs(dY))
    {
        //qDebug()<<"left or right";
        if (dX < 0)
            emit GestureMove(LEFT);
        else
            emit GestureMove(RIGHT);
    }
    else
    {
        //qDebug()<<"up or dowm";
        if (dY < 0)
            emit GestureMove(UP);
        else
            emit GestureMove(DOWN);
    }
}

//鼠标移动事件处理的槽函数
void GameWidget::onGestureMove(GestureDirect direct)
{
    int i, j, k;
    // 是否合并过方格
    bool combine = false;
    // 处理不同方向
    switch (direct)
    {
    // 向左
    case LEFT:
        // 循环每一行
        for (i = 0; i < 4; i++)
        {
            /* 初始化j k为0
             * 这里j表示要交换的数字列号
             * k表示交换到的位置的列号
             * */
            j = 0, k = 0, combine = false;
            while (true)
            {
                // 循环找到第一个不是0的数字对应的列号
                while (j < 4 && board[i][j] == 0)
                    j++;
                // 如果超过了3则说明搜索完毕 推出循环
                if (j > 3)
                    break;

                // 交换两个数字
                qSwap(board[i][k], board[i][j]);

                //如果交换后的数字与其前一列的数字相同
                if (!combine && k > 0 && board[i][k] == board[i][k - 1])
                {
                    // 前一列的数字*2
                    board[i][k - 1] <<= 1;
                    // 这一列的数字置为0
                    board[i][k] = 0;

                    // 数码个数-1
                    digitCount--;
                    combine = true;
                }
                else
                    k++;
                j++;
            }
        }
        break;
        // 其余三个方向与左向类似
    case RIGHT:
        for (i = 0; i < 4; i++)
        {
            j = 3, k = 3, combine = false;
            while (true)
            {
                while (j > -1 && board[i][j] == 0)
                    j--;
                if (j < 0)
                    break;
                qSwap(board[i][k], board[i][j]);

                if (!combine && k < 3 && board[i][k] == board[i][k + 1])
                {
                    board[i][k + 1] <<= 1;
                    board[i][k] = 0;

                    digitCount--;
                    combine = true;
                }
                else
                    k--;
                j--;
            }
        }
        break;
    case UP:
        for (i = 0; i < 4; i++)
        {
            j = 0, k = 0, combine = false;
            while (true)
            {
                while (j < 4 && board[j][i] == 0)
                    j++;
                if (j > 3)
                    break;
                qSwap(board[k][i], board[j][i]);

                if (!combine && k > 0 && board[k][i] == board[k - 1][i])
                {
                    board[k - 1][i] <<= 1;
                    board[k][i] = 0;

                    digitCount--;
                    combine = true;
                }
                else
                    k++;
                j++;
            }
        }
        break;
    case DOWN:
        for (i = 0; i < 4; i++)
        {
            j = 3, k = 3, combine = false;
            while (true)
            {
                while (j > -1 && board[j][i] == 0)
                    j--;
                if (j < 0)
                    break;
                qSwap(board[k][i], board[j][i]);

                if (!combine && k < 3 && board[k][i] == board[k + 1][i])
                {
                    board[k + 1][i] <<= 1;
                    board[k][i] = 0;

                    digitCount--;
                    combine = true;
                }
                else
                    k--;
                j--;
            }
        }
        break;
    }
    update();


    // 如果数字是否填满
    if (digitCount != 16)
    {
        // 随机产生行号和列号
        i = rand() % 4, j = rand() % 4;
        // 循环直到行和列对应的元素为0
        while (board[i][j] != 0)
            i = rand() % 4, j = rand() % 4;
        // 填入2
        //board[i][j] = (rand() % 2 + 1) * 2;
        board[i][j] = 2;
        // 数码个数加一
        digitCount++;
    }
    else
    {
        // 如果数字填满了 检测游戏是否over
        if (checkGameOver())
            emit GameOver();// 如果游戏over了则发射GameOver信号
    }

    // 检测游戏是否获胜
    if (checkWin())
        emit win();// 如果获胜则发射win信号
}

bool GameWidget::checkGameOver()
{
    // 循环检测是否含有相邻的相同数码
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
        {
            if (j != 3 && board[i][j] == board[i][j + 1])
                return false;
            if (i != 3 && board[i][j] == board[i + 1][j])
                return false;
        }
    return true;
}

bool GameWidget::checkWin()
{
    // 循环检测是否某个方格的数字为2048
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (board[i][j] == 2048)
                return true;
    return false;
}

void GameWidget::restart()
{
    // 初始化board数组
    memset(board, 0, sizeof(board));
    // 随机填入两个2
    board[rand() % 4][rand() % 4] = 2;
    while(true) {
        int x = rand() % 4;
        int y = rand() % 4;
        if (board[x][y] != 0) {
            continue;
        }
        else {
            board[x][y] = 2;
            break;
        }
    }
    // 数码个数初始化为2
    digitCount = 2;
    update();
}
