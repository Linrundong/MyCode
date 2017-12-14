#ifndef DISHITEM_H
#define DISHITEM_H

#include <QDialog>

typedef struct dish_struct{
    int id;
    QString name;
    QString pic_name;
    int price;
}dish_s;

namespace Ui {
class dishitem;
}

class dishitem : public QDialog
{
    Q_OBJECT

public:
    explicit dishitem(QWidget *parent = 0);
    ~dishitem();
    void setDish(dish_s dish);

    dish_s dish;

signals:
    void PopDish(dish_s);
    void PushDish(dish_s);


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::dishitem *ui;

};

#endif // DISHITEM_H
