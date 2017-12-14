#ifndef FINGERRECORD_H
#define FINGERRECORD_H

#include <QDialog>
#include "Sql/FingerBase.h"
#include <QVector>
#include <utility>
#include"mylineedit.h"
#include "keyboard.h"

namespace Ui {
class FingerRecord;
}

class FingerRecord : public QDialog
{
    Q_OBJECT

public:
    explicit FingerRecord(QWidget *parent = 0);
    ~FingerRecord();

private slots:
    void on_buttonBox_accepted();

    void on_addStuButton_clicked();

    void slotfornameedit();

    void slotforidedit();

private:
    void initClassNum();
    void setEditRule();
    void registerFinger();

private:
    Ui::FingerRecord *ui;
    FingerBase m_FingerBase;
    MyLineEdit *nameedit;
    MyLineEdit *idedit;
    Widget * keyboardforname;
    Widget * keyboardforid;
};

#endif // FINGERRECORD_H
