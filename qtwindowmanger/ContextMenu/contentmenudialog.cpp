#include "contentmenudialog.h"

#include <QMessageBox>

ContentMenuDialog::ContentMenuDialog(QWidget *parent)
    : QDialog(parent)
{
    list_widget=new QListWidget(this);
    list_widget->insertItem(0,"1111");
    list_widget->insertItem(1,"2222");
    list_widget->insertItem(2,"3333");
    list_widget->insertItem(3,"1111");
    list_widget->insertItem(4,"2222");
    list_widget->insertItem(5,"3333");
    list_widget->insertItem(6,"1111");
    list_widget->insertItem(7,"2222");
    list_widget->insertItem(8,"3333");
    list_widget->insertItem(9,"1111");
    list_widget->insertItem(10,"2222");
    list_widget->insertItem(11,"3333");
    list_widget->insertItem(12,"1111");
    list_widget->insertItem(13,"2222");
    list_widget->insertItem(14,"3333");
    list_widget->insertItem(15,"1111");
    list_widget->insertItem(16,"2222");
    list_widget->insertItem(17,"3333");
    list_widget->insertItem(18,"....");

    cmenu=NULL;
    setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(show_mouse_menu(QPoint)));

    line=new QLineEdit(this);
    line->setEnabled(false);
    QString data("111");
    for(int i=0;i<100;i++){
        data=data+QString::number(i);
    }
    line->setText(data);
    main_layout=new QVBoxLayout();
    this->setLayout(main_layout);
    main_layout->addWidget(list_widget);
    main_layout->addWidget(line);
    label=new QLabel();
    label->setText("111");
    main_layout->addWidget(label);
    label->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(label,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(show_message()));
}

ContentMenuDialog::~ContentMenuDialog()
{

}
void ContentMenuDialog::show_mouse_menu(QPoint point)
{
    if(cmenu){
        delete cmenu;
        cmenu=NULL;
    }
    cmenu=new QMenu(this);


    if(list_widget->itemAt(mapFromGlobal(QCursor::pos()))!=NULL){
        cmenu->addAction("111");
        cmenu->addAction("222");
    }else{
        cmenu->addAction("111*");
        cmenu->addAction("222*");
    }
    cmenu->exec(QCursor::pos());

}
void ContentMenuDialog::show_message(){
    QString data="<div>标题</div><div><table border='1'><tr><td>start</td><td>10:40</td></tr><tr><td>结束</td><td>10:40</td></tr><tr><td>提醒时间</td><td>10:40</td></tr></table></div>";
    QLabel message;
    message.setText(data);
    QMessageBox::about(this,tr("详细信息"),data);
    return;
}
