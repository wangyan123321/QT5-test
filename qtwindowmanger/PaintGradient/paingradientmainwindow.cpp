#include "paingradientmainwindow.h"

PainGradientMainWindow::PainGradientMainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setMouseTracking(true);
}

PainGradientMainWindow::~PainGradientMainWindow()
{

}

//窗口是基于逻辑坐标，视口是基于物理坐标
//void QPainter::setWindow(int x,int y,int width,int height);设置窗口坐标
//void QPainter::setViewport(int x,int y,int width,int height);设置视口坐标
//x:窗口 视口坐标的左上角x轴坐标
//y:窗口 视口坐标的左上角y轴坐标
//width:窗口 视口的长度
//height:窗口 视口的高度
/***
 * QPainter是一个状态机，当我们想绘制某些图像时，就可能想保存当前状态，在之后的某个图像是回复当前的状态，
 * QPainter提供了内置的函数：save()和restore()。
 * save()保存当前的状态
 * restore()恢复上一次保存的结果
 * 而且这两个函数必须成对出现
 */
void PainGradientMainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
//    painter.setBrush(Qt::green);
    //    painter.drawRect(0,0,20,20);//矩形绘制
    //    painter.setWindow(0,0,100,100);
    //    painter.drawRect(0,0,20,20);
//    int side=qMin(width(),height());
//    int x=(width()/2);
//    int y=(height()/2);

//    painter.setViewport(x,y,side,side);
//    painter.setWindow(0,0,100,100);

//    painter.setBrush(Qt::green);
//    painter.drawRect(0,0,20,20);
    painter.fillRect(10,10,50,100,Qt::red);
    painter.save();
    painter.translate(100,0);
    painter.fillRect(10,10,50,100,Qt::yellow);
    painter.restore();
    painter.translate(300,0);
    painter.rotate(30);
    painter.fillRect(10,10,50,100,Qt::green);
}
void PainGradientMainWindow::mouseMoveEvent(QMouseEvent *event){
    QString pos=QString("%1,%2").arg(event->pos().x()).arg(event->pos().y());
    QToolTip::showText(event->globalPos(),pos,this);
}
//void PainGradientMainWindow::paintEvent(QPaintEvent *event)
//{
//    QPainter painter(this);

//    painter.setRenderHint(QPainter::Antialiasing,true);
////    QLinearGradient linear_gradient(60,50,200,200);
////    linear_gradient.setColorAt(0.2,Qt::white);
////    linear_gradient.setColorAt(0.6,Qt::green);
////    linear_gradient.setColorAt(1.0,Qt::black);
////    painter.setBrush(QBrush(linear_gradient));
////    painter.drawEllipse(50,50,200,150);

//    QConicalGradient conical_gradient1(0,0,0);
//    const int r=150;

//    conical_gradient1.setColorAt(0.0,Qt::red);
//    conical_gradient1.setColorAt(60.0/360.0,Qt::yellow);
//    conical_gradient1.setColorAt(120.0/360.0,Qt::green);
//    conical_gradient1.setColorAt(180.0/360.0,Qt::cyan);
//    conical_gradient1.setColorAt(240.0/360.0,Qt::blue);
//    conical_gradient1.setColorAt(300.0/360.0,Qt::magenta);
//    conical_gradient1.setColorAt(1.0,Qt::red);

//    painter.translate(r,r);
//    painter.setPen(Qt::NoPen);
//    QBrush brush(conical_gradient1);
//    painter.setBrush(brush);
//    painter.drawEllipse(QPoint(0,0),r,r);
//}
