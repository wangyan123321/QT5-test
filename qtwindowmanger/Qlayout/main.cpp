#include "qlayoutwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QLayoutWindow w;
    w.show();

    return a.exec();
}
