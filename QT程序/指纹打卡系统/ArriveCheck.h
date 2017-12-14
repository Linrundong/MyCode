#ifndef ARRIVECHECK_H
#define ARRIVECHECK_H

#include <QDialog>
#include "Sql/FingerBase.h"


namespace Ui {
class ArriveCheck;
}

class ArriveCheck : public QDialog
{
    Q_OBJECT

public:
    explicit ArriveCheck(QWidget *parent = 0);
    ~ArriveCheck();

private slots:
    void on_nameBox_currentIndexChanged(int index);

    void on_classesBox_currentIndexChanged(int index);

    void on_dateBox_currentIndexChanged(int index);

    void on_filtrateBox_currentIndexChanged(int index);

    void on_arriveReturnButton_clicked();

private:
    void initTerm();
    QString timeCmp(QString arriveTime, QString scheduleTime, int flag);
    void addRecord(int col, QString stuNum, QString name, QString time, QString schedule, QString result);
    void setTableData();
private:
    Ui::ArriveCheck *ui;
    FingerBase m_FingerBase;
};

#endif // ARRIVECHECK_H
