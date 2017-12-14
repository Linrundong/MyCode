#ifndef MAINWIN_H
#define MAINWIN_H

#include <QDialog>

namespace Ui {
    class Dialog;
}
class FingerRecord;
class Password;
class ArriveCheck;

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void on_fingerRecordButton_clicked();
    void on_arriveCheckButton_clicked();
    void on_systemManagerButton_clicked();

private:
    void setBackground();
private:
    Ui::Dialog *ui;
    FingerRecord* m_Record;
    ArriveCheck* m_ArriveCheck;
    Password* m_Password;
};

#endif // MAINWIN_H
