#include "clockdialog.h"

ClockDialog::ClockDialog(QWidget *parent)
    : QDialog(parent)
{
    digtal=new DigiClock();
    main_layout=new QVBoxLayout();
    this->setLayout(main_layout);
    main_layout->addWidget(digtal);
    line_edit1=new QLineEdit();
    line_edit2=new QLineEdit();
    line_edit3=new QLineEdit();

    main_layout->addWidget(line_edit1);
    main_layout->addWidget(line_edit2);
    main_layout->addWidget(line_edit3);

    QPalette p=palette();
    p.setColor(QPalette::Window,Qt::blue);
    setPalette(p);
    setWindowFlags(Qt::FramelessWindowHint);
    setWindowOpacity(0.5);
}

ClockDialog::~ClockDialog()
{

}
void ClockDialog::mousePressEvent(QMouseEvent *event){
    if(event->button()==Qt::LeftButton){
        drag_positon=event->globalPos()-frameGeometry().topLeft();
        event->accept();
    }
}
void ClockDialog::mouseMoveEvent(QMouseEvent *event){
    if(event->buttons()&Qt::LeftButton){
        move(event->globalPos()-drag_positon);
        event->accept();
    }
}
