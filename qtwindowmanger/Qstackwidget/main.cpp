#include "stackdialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    stackDialog w;
    w.show();

    return a.exec();
}
