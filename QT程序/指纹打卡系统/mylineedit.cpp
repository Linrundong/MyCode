#include"mylineedit.h"


MyLineEdit::MyLineEdit(QWidget *parent)
                    :QLineEdit(parent)
{
    setFocusPolicy(Qt::ClickFocus);
}

void MyLineEdit::focusInEvent(QFocusEvent *event)
{
    clearFocus();
    emit editSignal();
    clearFocus();
    //QLineEdit::focusInEvent(event);
}
