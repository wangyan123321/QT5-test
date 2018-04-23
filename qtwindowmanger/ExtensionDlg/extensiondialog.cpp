#include "extensiondialog.h"

ExtensionDialog::ExtensionDialog(QWidget *parent)
    : QDialog(parent)
{
    base_info=new QWidget();
    detail_info=new QWidget();

    creatBaseInfo();
    creatDetailInfo();

    main_layout=new QVBoxLayout(this);
    main_layout->addWidget(base_info);
    main_layout->addWidget(detail_info);

    main_layout->setSizeConstraint(QLayout::SetFixedSize);
    main_layout->setSpacing(10);
}

ExtensionDialog::~ExtensionDialog()
{

}
void ExtensionDialog::showDetailInfo(){
    if(detail_info->isHidden()){
        detail_info->show();
    }else{
        detail_info->hide();
    }
}
void ExtensionDialog::creatBaseInfo(){

    QGridLayout *main_layout1=new QGridLayout(base_info);
    QLabel *name=new QLabel();
    name->setText("姓名");
    QLabel *sex=new QLabel();
    sex->setText("性别");
    QLineEdit *name_edit=new QLineEdit();
    QComboBox *sex_combox=new QComboBox();
    sex_combox->insertItem(0,"man");
    sex_combox->insertItem(1,"lady");
    QPushButton *ok_button=new QPushButton("确定");
    QPushButton *detail_button=new QPushButton("详细信息");

    main_layout1->addWidget(name,0,0);
    main_layout1->addWidget(name_edit,0,1);
    main_layout1->addWidget(ok_button,0,2);
    main_layout1->addWidget(sex,1,0);
    main_layout1->addWidget(sex_combox,1,1);
    main_layout1->addWidget(detail_button,1,2);

    main_layout1->setColumnStretch(0,1);
    main_layout1->setColumnStretch(1,2);
    main_layout1->setColumnStretch(2,1);
    connect(detail_button,SIGNAL(clicked(bool)),this,SLOT(showDetailInfo()));
}
void ExtensionDialog::creatDetailInfo(){
    QGridLayout *main_layout2=new QGridLayout(detail_info);

    QLabel *age=new QLabel("年龄");
    QLineEdit *age_edit=new QLineEdit();
    QLabel *department=new QLabel("部门");
    QComboBox *department_combox=new QComboBox();
    department_combox->insertItem(0,"无人");
    department_combox->insertItem(1,"控制");
    department_combox->insertItem(2,"总体");
    department_combox->insertItem(3,"飞行");
    main_layout2->addWidget(age,0,0);
    main_layout2->addWidget(age_edit,0,1,1,2);
    main_layout2->addWidget(department,1,0);
    main_layout2->addWidget(department_combox,1,1,1,2);

    main_layout2->setColumnStretch(0,1);
    main_layout2->setColumnStretch(1,2);
    main_layout2->setColumnStretch(2,1);

    detail_info->hide();
}
