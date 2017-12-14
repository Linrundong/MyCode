#ifndef ADDSCHEDULE_H
#define ADDSCHEDULE_H

#include <QDialog>
#include "Sql/FingerBase.h"
#include "AddDialog.h"

namespace Ui {
class AddSchedule;
}

class AddSchedule : public QDialog
{
    Q_OBJECT

public:
    explicit AddSchedule(QWidget *parent = 0);
    ~AddSchedule();
    void addRecord(int col, QString schName, QString time, QString start, QString end, QString flag);

private slots:
    void setTableData();

    void on_deleteButton_clicked();
    void on_addButton_clicked();
    void on_returnButton_clicked();

private:
    QVector<schedule> m_Data;
    Ui::AddSchedule *ui;
    FingerBase m_FingerBase;
    AddDialog* m_AddDialog;
};

#endif // ADDSCHEDULE_H
