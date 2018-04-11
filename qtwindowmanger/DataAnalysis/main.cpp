#include "dataanatysismainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSplitter *main_splitter;

    main_splitter=new QSplitter(Qt::Horizontal,0);
    QListWidget *left_widget;
    DataAnatysisMainWindow *manu=new DataAnatysisMainWindow();
    main_splitter->setOpaqueResize(true);
    main_splitter->setMinimumSize(main_splitter->minimumSize());
    main_splitter->setMaximumSize(main_splitter->maximumSize());

    left_widget=new QListWidget(main_splitter);
    left_widget->insertItem(0,QObject::trUtf8("插入数据"));
    left_widget->insertItem(1,"数据挖掘");
    left_widget->insertItem(2,"机器学习");
    left_widget->insertItem(3,"帮助");
    main_splitter->addWidget(left_widget);

//    DataAnatysisMainWindow w;
//    w.show();

    main_splitter->addWidget(manu->right_stack);
    QObject::connect(left_widget,SIGNAL(currentRowChanged(int)),manu->right_stack,SLOT(setCurrentIndex(int)));

    main_splitter->show();
    return a.exec();
}
