#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMenu>
#include<QLabel>
#include <QToolBar>
#include<QIcon>
#include<QDebug>
#include<QMessageBox>
#include<QFileDialog>
#include<QFile>
#include <QFontDialog>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->action_4->setChecked(false);
    ui->statusBar->hide();

    QLabel *l = new QLabel;
    l->setText("大吉大利，今晚吃鸡");
    ui->statusBar->addWidget(l);

    f = new findwindow;
    connect(f,SIGNAL(signalfind(QString)),this,SLOT(slotsforfind(QString)));
    connect(f,SIGNAL(signalfind2(QString)),this,SLOT(slotsforfind2(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete f;
}

void MainWindow::slotsforfind(QString str)
{
    ui->textEdit->find(str);
}

void MainWindow::slotsforfind2(QString str)
{
    ui->textEdit->find(str,QTextDocument::FindBackward);
}

void MainWindow::on_action_4_triggered(bool checked)
{
    qDebug()<<checked;
    if(checked==true)
    {
        ui->statusBar->show();
    }
    else
    {
        ui->statusBar->hide();
    }
}



void MainWindow::on_action_C_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_find_triggered()
{
    f->show();
}

void MainWindow::on_action_5_triggered()
{
    QMessageBox::aboutQt(0);
}

void MainWindow::on_action_O_triggered()
{
    QString fileName = QFileDialog::getOpenFileName();
    this->name = fileName;

    setWindowTitle(fileName);

    QFile f(fileName);
    f.open(QIODevice::ReadWrite);
    QString line=f.readAll();//读取所有的内容
    ui->textEdit->setText(line);
    f.close();
}

void MainWindow::on_action_triggered()
{
    qDebug()<<"11";
}

void MainWindow::on_save_triggered()
{
    QFile f(this->name);
    f.open(QIODevice::WriteOnly);
    QString tmp=ui->textEdit->document()->toPlainText();
    this->text = tmp;
    QTextStream out(&f);
    out <<tmp <<endl;
    f.close();
     qDebug()<<this->name<<"save succeed";
}

void MainWindow::on_save_as_triggered()
{
    QString filename = QFileDialog::getSaveFileName();

    QFile f(filename);
    f.open(QIODevice::WriteOnly);
    QString tmp=ui->textEdit->document()->toPlainText();
    this->text = tmp;
    QTextStream out(&f);
    out <<tmp <<endl;
    f.close();
     qDebug()<<this->name<<"save as succeed";
}

void MainWindow::on_new_2_triggered()
{
    //获取当前textedit内容
    QString tmp=ui->textEdit->document()->toPlainText();
    //内容没有改变了
    if(tmp==this->text)
    {
    }
    //内容改变了
    else
    {
        //question
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "警告", "文件已修改，是否保存", QMessageBox::Yes | QMessageBox::No);
        if(reply == QMessageBox::Yes)
        {
            if(this->name==NULL)
            {
                //打开文件弹窗
                QString filename = QFileDialog::getSaveFileName();
                QFile f(filename);
                f.open(QIODevice::WriteOnly);
                QTextStream out(&f);
                out <<tmp <<endl;
                f.close();
            }
            else
            {
                QFile f(this->name);
                f.open(QIODevice::WriteOnly);
                QTextStream out(&f);
                out <<tmp <<endl;
                f.close();
            }
        }
        else
        {
            //ui->textEdit->clear();

        }
    }
    QString t = NULL;
    this->name = t;
    ui->textEdit->clear();
    this->text=ui->textEdit->document()->toPlainText();
}

void MainWindow::on_font_triggered()
{
    //弹出设置字体的弹窗
    //定义bool型输出变量
    bool enable = false;
    //调用文字属性设置变量,传输输入变量enable用于保存是否点击了ok按钮，第二个参数为文字属性对话框默认值
    QFont font = QFontDialog::getFont(&enable);
    qDebug()<<font;
    //当点击属性对话框的ok按钮后，变量enable的值为true
    if(enable)
    {
        ui->textEdit->setFont(font);
    }
}

void MainWindow::on_paste_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::on_shear_triggered()
{
    ui->textEdit->cut();
}

void MainWindow::on_delete_2_triggered()
{
    ui->textEdit->clear();
}

void MainWindow::on_redo_triggered()
{
    ui->textEdit->redo();
}

void MainWindow::on_choall_triggered()
{
    ui->textEdit->selectAll();
}

void MainWindow::on_action_X_triggered()
{
    close();
}
