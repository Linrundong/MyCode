#include "widget.h"
#include<QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setBaseSize(QSize(2000, 2000));

    setAutoFillBackground(true);
    QPalette pal = palette();
    pal.setColor(QPalette::Background, QColor("#FAF8F0"));
    setPalette(pal);

    //添加2048标签
    titleLabel = new QLabel(tr("2048"), this);
    titleLabel->setStyleSheet("color:#746D65;");
    titleLabel->setGeometry(10,10,150,50);
    titleLabel->setFont(QFont("arial", 30, QFont::Black));

    //添加说明标签
    tipsLabel = new QLabel(tr("Join the numbers and get to the 2048 tile!"), this);
    tipsLabel->setStyleSheet("color:#B3AFA7;");
    tipsLabel->setGeometry(10,60,300,20);
    tipsLabel->setFont(QFont("arial", 7, QFont::Normal));

    // 构造一个字体对象
    QFont font;
    font.setFamily("Arial");
    font.setBold(true);
    font.setPixelSize(15);

    // 构造一个Newgame按钮对象
    restartBtn = new QPushButton("New Game", this);
    restartBtn->setGeometry(250, 50, 150, 40);
    restartBtn->setFont(font);
    restartBtn->setStyleSheet("QPushButton{color: white;background:#907963;border-style:flat;}");

    // 构造一个游戏部件对象
    gameWidget = new GameWidget(this);
    gameWidget->setGeometry(2, 100, 400, 400);

    connect(restartBtn, SIGNAL(clicked()), gameWidget, SLOT(restart()));
    connect(gameWidget, SIGNAL(GameOver()), this, SLOT(onGameOver()));
    connect(gameWidget, SIGNAL(win()), this, SLOT(onWin()));
}

Widget::~Widget()
{
    // 释放相关对象
    delete restartBtn;
    delete gameWidget;
}

void Widget::onGameOver()
{
    QMessageBox::information(this, "GameOver", "You lost !");
}

void Widget::onWin()
{
    QMessageBox::information(this, "Congratulation", "You win !");
}



