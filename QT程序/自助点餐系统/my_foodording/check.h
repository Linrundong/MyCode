#ifndef CHECK_H
#define CHECK_H

#include <QDialog>

namespace Ui {
class check;
}

class check : public QDialog
{
    Q_OBJECT

signals:
    void oversignal();

public:
    explicit check(QWidget *parent = 0);
    void setprice(QString);
    ~check();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::check *ui;
};

#endif // CHECK_H
