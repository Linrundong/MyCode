#ifndef SQLWIDGET_H
#define SQLWIDGET_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>

namespace Ui {
class sqlwidget;
}

class sqlwidget : public QWidget
{
    Q_OBJECT

signals:
    void showsqlwidget();

public:
    explicit sqlwidget(QWidget *parent = 0);
    ~sqlwidget();
    void show_tableview(QSqlDatabase);

public:
    Ui::sqlwidget *ui;
private slots:
    void on_pushButton_clicked();
};

#endif // SQLWIDGET_H
