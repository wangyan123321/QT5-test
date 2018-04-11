#include "datainsertwindow.h"

DataInsertWindow::DataInsertWindow(QWidget *parent) : QWidget(parent)
{
    main_layout=new QGridLayout(this);
    main_layout->setSizeConstraint(QLayout::SetFixedSize);

    test=new QLabel("数据插入窗口");

    main_layout->addWidget(test,0,0);
}
