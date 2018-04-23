#include "shapedialog.h"

ShapeDialog::ShapeDialog(QWidget *parent)
    : QDialog(parent)
{
    QPixmap pix;
    pix.load("D:/Qt5/plant.jpg",0,Qt::AvoidDither|Qt::ThresholdAlphaDither|Qt::ThresholdDither);
    resize(pix.size());
    setMask(QBitmap(pix.mask()));
    setWindowFlags(Qt::FramelessWindowHint);
}

ShapeDialog::~ShapeDialog()
{

}
void ShapeDialog::mouseMoveEvent(QMouseEvent *event){

    if(event->buttons()&Qt::LeftButton){
        move(event->globalPos()-drag_position);
        event->accept();
    }
}
void ShapeDialog::mousePressEvent(QMouseEvent *event){
    if(event->button()==Qt::LeftButton){
        drag_position=event->globalPos()-frameGeometry().topLeft();
        event->accept();
    }

}
void ShapeDialog::paintEvent(QPaintEvent *){
    QPainter painter(this);
    painter.drawPixmap(0,0,QPixmap("D:/Qt5/plant.jpg"));
}
