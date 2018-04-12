#include "qtoolboxwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QToolBoxWidget w;
    w.show();

    return a.exec();
}
