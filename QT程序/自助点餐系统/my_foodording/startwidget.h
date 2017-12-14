#ifndef STARTWIDGET_H
#define STARTWIDGET_H

#include <QWidget>
#include"widget.h"

namespace Ui {
class startwidget;
}

class startwidget : public QWidget
{
    Q_OBJECT

public:
    explicit startwidget(QWidget *parent = 0);
    ~startwidget();

private slots:
    void on_pushButton_clicked();

private:
    Ui::startwidget *ui;
    Widget *w;
};

#endif // STARTWIDGET_H
