#include "alltestmainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    AllTestMainWindow w;
//    w.show();
    QSplitter *splitter_main=new QSplitter(Qt::Horizontal,0);

    QListWidget *list=new QListWidget(splitter_main);
    list->insertItem(0,QObject::tr("基本信息"));
    list->insertItem(1,QObject::tr("联系方式"));
    list->insertItem(2,QObject::tr("详细信息"));

    AllTestMainWindow *conten=new AllTestMainWindow(splitter_main);

    QObject::connect(list,SIGNAL(currentRowChanged(int)),conten->stack_window,SLOT(setCurrentIndex(int)));


    splitter_main->setMinimumSize(splitter_main->minimumSize());
    splitter_main->setMaximumSize(splitter_main->maximumSize());

    splitter_main->show();

    return a.exec();
}
