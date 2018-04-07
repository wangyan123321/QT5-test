#include "alltestmainwindow.h"
#include <QVBoxLayout>

AllTestMainWindow::AllTestMainWindow(QWidget *parent) :
    QFrame(parent)
{
//    main_window=new QSplitter(Qt::Horizontal,this);
//    //main_window->setOpaqueResize(true);
//    left_list_wiget=new QListWidget(main_window);
    right_layout=new QVBoxLayout(this);

//    left_list_wiget->insertItem(0,QObject::tr("基本信息"));
//    left_list_wiget->insertItem(1,QObject::tr("联系方式"));
//    left_list_wiget->insertItem(2,QObject::tr("详细资料"));

    stack_window=new QStackedWidget();
    stack_window->setFrameStyle(QFrame::Panel|QFrame::Raised);

    base_info=new baseInfo();
    contect_info=new contactInfo();
    detail_info=new detailInfo();

    stack_window->addWidget(base_info);
    stack_window->addWidget(contect_info);
    stack_window->addWidget(detail_info);

    amend_button=new QPushButton(QObject::tr("修改"));
    close_button=new QPushButton(QObject::tr("取消"));
    bottom_layout=new QHBoxLayout();
    bottom_layout->addStretch(1);
    bottom_layout->addWidget(amend_button);
    bottom_layout->addWidget(close_button);

    right_layout->setMargin(10);
    right_layout->setSpacing(6);
    right_layout->addWidget(stack_window);
    right_layout->addLayout(bottom_layout);



   // main_window->setMinimumSize(this->minimumSize());
    //main_window->setMaximumSize(this->maximumSize());
}

AllTestMainWindow::~AllTestMainWindow()
{
}
