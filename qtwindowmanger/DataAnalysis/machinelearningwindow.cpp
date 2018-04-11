#include "machinelearningwindow.h"

MachineLearningWindow::MachineLearningWindow(QWidget *parent) : QWidget(parent)
{
    main_layout=new QGridLayout(this);
    main_layout->setSizeConstraint(QLayout::SetFixedSize);

    test=new QLabel("机器学习窗口");

    main_layout->addWidget(test,0,0);
}
