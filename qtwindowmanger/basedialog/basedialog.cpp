#include "basedialog.h"

basedialog::basedialog(QWidget *parent)
    : QDialog(parent)
{
    main_layout=new QGridLayout(this);
    main_layout->setMargin(15);
    main_layout->setSpacing(10);

    filename_select_label=new QLabel(QObject::tr("确认文件"));

    filename_select_edit=new QLineEdit();
    filename_select=new QPushButton(QObject::tr("确认文件"));


    filename_save_label=new QLabel(QObject::tr("保存文件"));
    filename_save_edit=new QLineEdit();
    filename_save=new QPushButton("保存文件");

    filedir_select_edit=new QLineEdit();
    filedir_select=new QPushButton("选择文件夹:");

    main_layout->addWidget(filename_select,0,0);
    main_layout->addWidget(filename_select_edit,0,1);

    main_layout->addWidget(filename_save,1,0);
    main_layout->addWidget(filename_save_edit,1,1);

    main_layout->addWidget(filedir_select_edit,2,1);
    main_layout->addWidget(filedir_select,2,0);

    connect(filename_select,SIGNAL(pressed()),this,SLOT(filenameSelect()));
    connect(filename_save,SIGNAL(pressed()),this,SLOT(filenameSave()));
    connect(filedir_select,SIGNAL(pressed()),this,SLOT(filedirSelect()));
}

basedialog::~basedialog()
{

}
void basedialog::filenameSave(){
    QString data;
    data=QFileDialog::getSaveFileName(this,"保存文件","/","C++ files(*.cpp);;C files(*.c)");
    filename_save_edit->setText(data);
}
void basedialog::filenameSelect(){
      QString data;
      data=QFileDialog::getOpenFileName(this,"选择确认的文件:","/","C++ files(*.cpp);;C files(*.c)");
      filename_select_edit->setText(data);
}
void basedialog::filedirSelect(){
    QString data;
    data=QFileDialog::getExistingDirectory(this,"选择文件夹:","/");
    filedir_select_edit->setText(data);
}
void basedialog::filelistSelect(){

}
