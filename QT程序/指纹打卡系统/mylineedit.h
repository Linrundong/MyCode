#ifndef MYLINEEDIT_H
#define MYLINEEDIT_H
#include<QLineEdit>
class MyLineEdit: public QLineEdit
{
    Q_OBJECT

public:
     MyLineEdit(QWidget *parent=0);
     virtual void focusInEvent(QFocusEvent *event);

signals:
     void editSignal();

};


#endif // MYLINEEDIT_H
