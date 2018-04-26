#include "imagetextmainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ImageTextMainWindow w;
    w.show();

    return a.exec();
}
