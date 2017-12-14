#ifndef SERVERWIDGET_H
#define SERVERWIDGET_H

#include <QWidget>
#include <QtNetwork>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "sqlwidget.h"

namespace Ui {
class serverwidget;
}

class serverwidget : public QWidget
{
    Q_OBJECT

public slots:
    void acceptConnection();
    void readClient();

public:
    explicit serverwidget(QWidget *parent = 0);
    ~serverwidget();
    QTcpServer *server;
    QTcpSocket *clientConnection;
    void sql_write(QString str);

private slots:
    void on_pushButton_clicked();
    void slotforhide();

private:
    Ui::serverwidget *ui;
    QString str;
    int flag=1;
    QSqlDatabase db;
    int m_i=0;

    sqlwidget *sqlwid;

};

#endif // SERVERWIDGET_H
