#ifndef QSPLASHMAINWINDOW_H
#define QSPLASHMAINWINDOW_H

#include <QMainWindow>

class QSplashMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QSplashMainWindow(QWidget *parent = 0);
    ~QSplashMainWindow();
};

#endif // QSPLASHMAINWINDOW_H
