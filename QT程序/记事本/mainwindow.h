#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"findwindow.h"
#include<QString>
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


public slots:
    void slotsforfind(QString str);
    void slotsforfind2(QString str);


private slots:
    void on_action_4_triggered(bool checked);


    void on_action_C_triggered();

    void on_find_triggered();

    void on_action_5_triggered();

    void on_action_O_triggered();

    void on_action_triggered();

    void on_save_triggered();

    void on_save_as_triggered();

    void on_new_2_triggered();

    void on_font_triggered();

    void on_paste_triggered();

    void on_shear_triggered();

    void on_delete_2_triggered();

    void on_redo_triggered();

    void on_choall_triggered();

    void on_action_X_triggered();

private:
    Ui::MainWindow *ui;
    findwindow *f;
    QString name=NULL;
    QString text=NULL;

};

#endif // MAINWINDOW_H
