#include "MainWin.h"
#include <QApplication>
#include "Sql/FingerBase.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    bool exist = FingerBase::baseExist();
    FingerBase::createConnection();
    if(!exist) {
        FingerBase::createBase();
    }

    Dialog w;
    w.show();

    return a.exec();
}
