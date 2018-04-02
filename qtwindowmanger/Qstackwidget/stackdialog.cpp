#include "stackdialog.h"

#include<QHBoxLayout>

/*
*QStackWidget堆栈窗体，堆栈窗体一般与列表框QListWidget及下拉列表框QCombox配合使用。
*本例子主要新建了个QStackedWidget类，通过点击不同的复选框，查看不同的窗口。
*
*/

stackDialog::stackDialog(QWidget *parent)
    : QDialog(parent)
{

    dock1=new QDockWidget(this);
    dock2=new QDockWidget(this);
    dock3=new QDockWidget(this);
    dock1->setFeatures(QDockWidget::AllDockWidgetFeatures);
    dock2->setFeatures(QDockWidget::AllDockWidgetFeatures);
    dock3->setFeatures(QDockWidget::AllDockWidgetFeatures);


    lable1=new QLabel(QObject::tr("lable1"));
    lable2=new QLabel(QObject::tr("lable2"));
    lable3=new QLabel(QObject::tr("lable3"));

    dock1->setWidget(lable1);
    dock2->setWidget(lable2);
    dock3->setWidget(lable3);

    listwidget=new QListWidget(this);//新建一个QListWidget控件对象

    listwidget->insertItem(0,QObject::tr("windows1"));
    listwidget->insertItem(1,QObject::tr("windows2"));
    listwidget->insertItem(2,QObject::tr("windows3"));

    stackwiget=new QStackedWidget(this);//实例化一个堆栈窗体
    //向堆栈窗体中加入三个窗口
    stackwiget->addWidget(dock1);
    stackwiget->addWidget(dock2);
    stackwiget->addWidget(dock3);

    QHBoxLayout *mainlayout=new QHBoxLayout(this);

    //对整个对话框进行布局
    mainlayout->setMargin(5);//设定对话框的边距为5
    mainlayout->setSpacing(5);//设定各个控件之间的间距。
    mainlayout->addWidget(listwidget);
    mainlayout->addWidget(stackwiget,0,Qt::AlignHCenter);
    mainlayout->setStretchFactor(listwidget,1);
    mainlayout->setStretchFactor(stackwiget,2);

    connect(listwidget,SIGNAL(currentRowChanged(int)),stackwiget,SLOT(setCurrentIndex(int)));
}

stackDialog::~stackDialog()
{

}
