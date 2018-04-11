#include "basedialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    basedialog w;
    w.show();

    return a.exec();
}
