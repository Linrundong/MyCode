#ifndef FINDWINDOW_H
#define FINDWINDOW_H

#include <QWidget>

namespace Ui {
class findwindow;
}

class findwindow : public QWidget
{
    Q_OBJECT
signals:
    void signalfind(QString str);
    void signalfind2(QString str);

public:
    explicit findwindow(QWidget *parent = 0);
    ~findwindow();


private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::findwindow *ui;

};

#endif // FINDWINDOW_H
