#include "qlayoutwindow.h"

QLayoutWindow::QLayoutWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(QObject::tr("UserInfo"));

    MainLayout=new QGridLayout(this);
    MainLayout->setMargin(15);
    MainLayout->setSpacing(10);


    LeftLayout=new QGridLayout();
    UserNameLable=new QLabel(QObject::tr("用户名："));
    Username=new QLineEdit();
    LeftLayout->addWidget(UserNameLable,0,0);
    LeftLayout->addWidget(Username,0,1);
    MainLayout->addLayout(LeftLayout,0,0);



}

QLayoutWindow::~QLayoutWindow()
{

}
