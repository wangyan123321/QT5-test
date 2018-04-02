#include "mainwindow.h"
#include <QApplication>
#include <QTextEdit>
#include<QDockWidget>

/*
 * 停靠窗口QDockWigit类
 * 创建婷靠窗口的基本流程
 * 1.创建一个QDockwiget对象的停靠窗口。
 * 2.设置此停靠窗口的属性，通常调用setFeatures及setAllowsAreas两种方法。
 * 3.新建一个要插入停靠窗体的控件，常用的有QListWidget和QTextEdit。
 * 4.将控件插入到停靠窗体，调用QDockWidget的setWidget方法。
 * 5.使用addDockWidget方法在MainWindow中加入此停靠窗口。
 * 例子中
 * 窗口1只可在主窗口的左边和右边停靠，
 * 窗口2可在浮动和右部停靠两种状态中切换，并且不可移动，
 * 窗口3课实现窗口的各种状态。
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.setWindowTitle(QObject::tr("DockWindows"));//设置主窗口的标签

    QTextEdit *te=new QTextEdit(&w);//将QTextEdit对象作为主窗口
    te->setText(QObject::tr("windows 1"));
    te->setAlignment(Qt::AlignCenter);
    w.setCentralWidget(te);//将QTextEdit作为主窗口的中央窗口

    //停靠窗口1
    QDockWidget *dock0=new QDockWidget(QObject::tr("Dock1"),&w);//创建停靠窗口
    QTextEdit *te0=new QTextEdit();
    te0->setText(QObject::tr("dock1 windows 111111"));
    dock0->setFeatures(QDockWidget::DockWidgetMovable);//设置停靠窗口的可移动属性(可移动，可关闭，可浮动，具有全部属性，全不具有)
    dock0->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);//设置窗口可停靠的区域（主窗口的左侧，主窗口的右侧，主窗口的顶端，主窗口的底端，任意位置，只可停靠在插入处）
    dock0->setWidget(te0);
    w.addDockWidget(Qt::RightDockWidgetArea,dock0);

    //停靠窗口2
    QDockWidget *dock1=new QDockWidget(QObject::tr("Dock2"),&w);
    QTextEdit *te1=new QTextEdit();
    te1->setText(QObject::tr("dock2 windows"));
    dock1->setFeatures(QDockWidget::DockWidgetClosable|QDockWidget::DockWidgetFloatable);
    dock1->setWidget(te1);
    w.addDockWidget(Qt::RightDockWidgetArea,dock1);



    //停靠窗口3
    QDockWidget *dock2=new QDockWidget(QObject::tr("Dock3"),&w);
    QTextEdit *te2=new QTextEdit(dock2);
    te2->setText(QObject::tr("dock3 windows"));
    dock2->setFeatures(QDockWidget::AllDockWidgetFeatures);
    dock2->setWidget(te2);
    w.addDockWidget(Qt::RightDockWidgetArea,dock2);


    w.show();

    return a.exec();
}
