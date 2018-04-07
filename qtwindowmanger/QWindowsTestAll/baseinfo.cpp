#include "baseinfo.h"

#include<QPixmap>
#include<QHBoxLayout>

baseInfo::baseInfo(QWidget *parent) : QWidget(parent)
{
    main_layout=new QGridLayout(this);
    main_layout->setMargin(15);
    main_layout->setSpacing(10);

    left_layout=new QGridLayout();
    left_layout->setColumnMinimumWidth(0,1);
    left_layout->setColumnMinimumWidth(1,3);

    right_layout=new QVBoxLayout();

    main_layout->addLayout(left_layout,0,0);
    main_layout->addLayout(right_layout,0,1);

    user_name=new QLabel(QObject::tr("用户:"));
    user_name_edit=new QLineEdit();
    name=new QLabel(QObject::tr("姓名:"));
    name_edit=new QLineEdit();
    sex=new QLabel(QObject::tr("性别:"));
    sex_select=new QComboBox();
    sex_select->insertItem(0,QObject::tr("男人:"));
    sex_select->insertItem(1,QObject::tr("女人:"));
    department=new QLabel("部门:");
    department_edit=new QTextEdit();
    other=new QLabel(QObject::tr("备注:"));
    other->setFrameStyle(QFrame::Panel|QFrame::Sunken);
    left_layout->addWidget(user_name,0,0);
    left_layout->addWidget(user_name_edit,0,1);
    left_layout->addWidget(name,1,0);
    left_layout->addWidget(name_edit,1,1);
    left_layout->addWidget(sex,2,0);
    left_layout->addWidget(sex_select,2,1);
    left_layout->addWidget(department,3,0);
    left_layout->addWidget(department_edit,3,1);
    left_layout->addWidget(other,4,0,1,2);

    head=new QLabel("头像");
    head_icon=new QLabel();
    QPixmap icon("E://123.png");
    head_icon->setPixmap(icon);
    head_update=new QPushButton(QObject::tr("确定:"));
    QHBoxLayout *head_layout=new QHBoxLayout();
    head_layout->addWidget(head);
    head_layout->addWidget(head_icon);
    head_layout->addWidget(head_update);
    right_layout->addLayout(head_layout);
    self_introduction=new QLabel(QObject::tr("详细描述:"));
    self_introduction_edit=new QTextEdit();
    right_layout->addWidget(self_introduction);
    right_layout->addWidget(self_introduction_edit);

}
