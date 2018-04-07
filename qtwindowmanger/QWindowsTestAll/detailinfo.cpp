#include "detailinfo.h"

detailInfo::detailInfo(QWidget *parent) : QWidget(parent)
{
    main_layout=new QGridLayout(this);
    main_layout->setMargin(15);
    main_layout->setSpacing(10);

    country_label=new QLabel(QObject::tr("国家/地区"));
    country_combox=new QComboBox();
    country_combox->insertItem(0,QObject::tr("中国:"));
    country_combox->insertItem(1,QObject::tr("美国:"));
    country_combox->insertItem(2,QObject::tr("英国:"));

    province_label=new QLabel(QObject::tr("省份:"));
    province_combox=new QComboBox();
    province_combox->insertItem(0,QObject::tr("吉林:"));
    province_combox->insertItem(1,QObject::tr("北京:"));
    province_combox->insertItem(2,QObject::tr("上海:"));

    city_label=new QLabel(QObject::tr("城市:"));
    city_edit=new QLineEdit();

    self_desc_label=new QLabel(QObject::tr("个人说明:"));
    self_desc_edit=new QTextEdit();

    main_layout->addWidget(country_label,0,0);
    main_layout->addWidget(country_combox,0,1);
    main_layout->addWidget(province_label,1,0);
    main_layout->addWidget(province_combox,1,1);
    main_layout->addWidget(city_label,2,0);
    main_layout->addWidget(city_edit,2,1);
    main_layout->addWidget(self_desc_label,3,0);
    main_layout->addWidget(self_desc_edit,3,1);
}
