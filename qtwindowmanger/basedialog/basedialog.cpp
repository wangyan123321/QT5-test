#include "basedialog.h"


#include <QColorDialog>
#include <QFontDialog>

/*
*添加几种基本对话框，包括：
* 文件操作对话框
* 标准颜色对话框
* 标准字体对话框
* 标准输入对话框
*/
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
    filedir_select=new QPushButton("选择文件夹啊");

    main_layout->addWidget(filename_select,0,0);
    main_layout->addWidget(filename_select_edit,0,1);

    main_layout->addWidget(filename_save,1,0);
    main_layout->addWidget(filename_save_edit,1,1);

    main_layout->addWidget(filedir_select_edit,2,1);
    main_layout->addWidget(filedir_select,2,0);

    color_button=new QPushButton("颜色选择");
    color_frame=new QFrame();
    color_frame->setFrameShape(QFrame::Box);
    color_frame->setAutoFillBackground(true);

    main_layout->addWidget(color_button,3,0);
    main_layout->addWidget(color_frame,3,1);

    font_button=new QPushButton("字体选择");
    font_test=new QLineEdit();
    font_test->setText("字体测试");

    main_layout->addWidget(font_button,4,0);
    main_layout->addWidget(font_test,4,1);

    input_button=new QPushButton("标准输入对话");
    main_layout->addWidget(input_button,5,0);

    connect(filename_select,SIGNAL(pressed()),this,SLOT(filenameSelect()));
    connect(filename_save,SIGNAL(pressed()),this,SLOT(filenameSave()));
    connect(filedir_select,SIGNAL(pressed()),this,SLOT(filedirSelect()));
    connect(color_button,SIGNAL(pressed()),this,SLOT(showColor()));
    connect(font_button,SIGNAL(pressed()),this,SLOT(showFont()));
    connect(input_button,SIGNAL(pressed()),this,SLOT(showStandInput()));
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
      data=QFileDialog::getOpenFileName(this,"选择确认文件:","/","C++ files(*.cpp);;C files(*.c)");
      filename_select_edit->setText(data);
}
void basedialog::filedirSelect(){
    QString data;
    data=QFileDialog::getExistingDirectory(this,"选择文件夹:","/");
    filedir_select_edit->setText(data);
}
void basedialog::showColor(){
    QColor color=QColorDialog::getColor(Qt::blue);
    if(color.isValid()){
        color_frame->setPalette(QPalette(color));//查看颜色是否被取消
    }
}
void basedialog::showFont(){
    bool ok=false;
    QFont font=QFontDialog::getFont(&ok);//选择字体颜色需要传入一个bool型变量地址
    if(ok){
        font_test->setFont(font);
    }

}
void basedialog::showStandInput(){
    standinput=new StandInput();
    standinput->show();
}
void basedialog::filelistSelect(){

}
