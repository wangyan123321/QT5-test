#include "contactinfo.h"

contactInfo::contactInfo(QWidget *parent) : QWidget(parent)
{
    main_layout=new QGridLayout(this);
    main_layout->setMargin(15);
    main_layout->setSpacing(10);
    main_layout->setSizeConstraint(QLayout::SetFixedSize);

    email_label=new QLabel(QObject::tr("电子邮件"));
    address_label=new QLabel(QObject::tr("联系地址"));
    mailnum_label=new QLabel(QObject::tr("邮政编码"));
    movble_phone_num_label=new QLabel(QObject::tr("移动电话"));
    leave_say=new QCheckBox(QObject::tr("接收留言"));

    email_edit=new QLineEdit();
    address_edit=new QLineEdit();
    mailnum_edit=new QLineEdit();
    movble_phone_num_edit=new QLineEdit();
    main_layout->addWidget(email_label,0,0);
    main_layout->addWidget(email_edit,0,1);
    main_layout->addWidget(address_label,1,0);
    main_layout->addWidget(address_edit,1,1);
    main_layout->addWidget(mailnum_label,2,0);
    main_layout->addWidget(mailnum_edit,2,1);
    main_layout->addWidget(movble_phone_num_label,3,0);
    main_layout->addWidget(movble_phone_num_edit,3,1);
    main_layout->addWidget(leave_say,3,2);

}
