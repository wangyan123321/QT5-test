#include "standinput.h"

#include <QInputDialog>

StandInput::StandInput(QWidget *parent) : QWidget(parent)
{
    main_layout=new QGridLayout(this);
    main_layout->setSpacing(15);
    main_layout->setMargin(10);

    int_input_button=new QPushButton("修改");
    float_input_button=new QPushButton("修改");
    int_input_edit=new QLineEdit();
    float_input_edit=new QLineEdit();
    age_label=new QLabel("年龄");
    high_label=new QLabel("身高");


    main_layout->addWidget(age_label,0,0);
    main_layout->addWidget(int_input_button,0,1);
    main_layout->addWidget(int_input_edit,0,2);
    main_layout->addWidget(high_label,1,0);
    main_layout->addWidget(float_input_button,1,1);
    main_layout->addWidget(float_input_edit,1,2);

    connect(int_input_button,SIGNAL(pressed()),this,SLOT(changeAge()));
}

void StandInput::changeAge(){
    bool ok;
    int age=QInputDialog::getInt(this,"标准","年龄",int_input_edit->text().toInt(&ok),0,100,1,&ok);
    if(ok){
        int_input_edit->setText(QString(tr("%1")).arg(age));
    }
}
void StandInput::changeHigh(){

}
