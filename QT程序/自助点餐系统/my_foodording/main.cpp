#include "widget.h"
#include "dishitem.h"
#include <QApplication>
#include "startwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    startwidget s;
    s.show();

    return a.exec();
}
