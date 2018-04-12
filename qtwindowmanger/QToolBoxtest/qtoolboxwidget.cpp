#include "qtoolboxwidget.h"

QToolBoxWidget::QToolBoxWidget(QWidget *parent)
    : QWidget(parent)
{

    //main_layout=new QGridLayout(this);
    //this->setLayout(main_layout);

    group_box1=new QGroupBox();

    qlist1=new QListWidget(group_box1);
    qlist1->insertItem(1,"test1");
    qlist1->insertItem(2,"test2");


    tool_box_1=new QToolBox(this);
    tool_box_1->addItem((QWidget*)group_box1,"test1");
    tool_box_2=new QToolBox(this);
    group_box2=new QGroupBox();
    tool_box_1->addItem((QWidget*)group_box2,"test2");

   // main_layout->addItem(tool_box_1,0,0);

}

QToolBoxWidget::~QToolBoxWidget()
{

}
