#include "paintewidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PainteWidget w;
    w.show();

    return a.exec();
}
