#include "dataminingwindow.h"

DataMiningWindow::DataMiningWindow(QWidget *parent) : QWidget(parent)
{
    main_layout=new QGridLayout(this);
    main_layout->setSizeConstraint(QLayout::SetFixedSize);

    test=new QLabel("数据挖掘窗口");

    main_layout->addWidget(test,0,0);
}
