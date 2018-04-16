#include "contentmenudialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ContentMenuDialog w;
    w.show();

    return a.exec();
}
