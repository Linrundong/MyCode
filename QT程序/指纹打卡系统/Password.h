#ifndef PASSWORD_H
#define PASSWORD_H

#include <QDialog>

namespace Ui {
class Password;
}
class SystemManager;

class Password : public QDialog
{
    Q_OBJECT

public:
    explicit Password(QWidget *parent = 0);
    ~Password();

private slots:
    void on_enterButton_clicked();
    void on_passwordReturnButton_clicked();


private:
    Ui::Password *ui;
    SystemManager* m_SystemManager;
};

#endif //PASSWORD_H
