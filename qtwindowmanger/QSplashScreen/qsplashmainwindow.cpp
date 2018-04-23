#include "qsplashmainwindow.h"

#include <QTextEdit>
#include <QGridLayout>
#include <QThread>

QSplashMainWindow::QSplashMainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("splash example");
    QTextEdit *edit=new QTextEdit(this);
    edit->setText("1111111111111");

    resize(600,450);
    QThread::sleep(10);
}

QSplashMainWindow::~QSplashMainWindow()
{

}
