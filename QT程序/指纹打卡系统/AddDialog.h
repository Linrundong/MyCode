#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include <QDialog>
#include "Sql/FingerBase.h"
#include "mylineedit.h"
#include "keyboard.h"


namespace Ui {
class AddDialog;
}

class AddDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddDialog(QWidget *parent = 0);
    ~AddDialog();

signals:
    void addRecord();

private slots:
    void on_okButton_clicked();
    void on_backButton_clicked();
    void slotforedit();

private:
    Ui::AddDialog *ui;
    FingerBase m_FingerBase;
    MyLineEdit *scheduleEdit;
    Widget *keyboard;
};

#endif // ADDDIALOG_H
