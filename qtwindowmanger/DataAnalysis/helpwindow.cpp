#include "helpwindow.h"

HelpWindow::HelpWindow(QWidget *parent) : QWidget(parent)
{
    main_layout=new QGridLayout(this);
    main_layout->setSizeConstraint(QLayout::SetFixedSize);

    test=new QLabel("帮助窗口");

    main_layout->addWidget(test,0,0);
}
