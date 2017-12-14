#ifndef NEWPASSWORD_H
#define NEWPASSWORD_H

#include <QDialog>
#include "mylineedit.h"
#include "keyboard.h"

namespace Ui {
class newpassword;
}

class newpassword : public QDialog
{
    Q_OBJECT

public:
    explicit newpassword(QWidget *parent = 0);
    ~newpassword();

private slots:
    void slotforedit();

private:
    Ui::newpassword *ui;
    MyLineEdit *passwdeEdit;
    Widget *keyboard;
};

#endif // NEWPASSWORD_H
