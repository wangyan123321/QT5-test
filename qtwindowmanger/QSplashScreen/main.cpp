#include "qsplashmainwindow.h"
#include <QApplication>
#include <QPixmap>
#include <QSplashScreen>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QPixmap pixmap("D:/Qt5/plant.jpg");
    QSplashScreen splash(pixmap);
    splash.show();
    a.processEvents();
    QSplashMainWindow w;
    w.show();
    splash.finish(&w);
    return a.exec();
}
