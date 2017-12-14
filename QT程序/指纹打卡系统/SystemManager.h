#ifndef SYSTEMMANAGER_H
#define SYSTEMMANAGER_H

#include <QDialog>
#include "AddSchedule.h"
#include"newpassword.h"

namespace Ui {
class SystemManager;
}

class SystemManager : public QDialog
{
    Q_OBJECT

public:
    explicit SystemManager(QWidget *parent = 0);
    ~SystemManager();

private slots:
    void on_ScheduleButton_clicked();
    void on_manageReturnButton_clicked();

    void on_passwordButton_clicked();

private:
    Ui::SystemManager *ui;
    AddSchedule* m_AddSchedule;
    newpassword * newpasswd;
};

#endif // SYSTEMMANAGER_H
