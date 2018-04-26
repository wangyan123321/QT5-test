#ifndef PAINGRADIENTMAINWINDOW_H
#define PAINGRADIENTMAINWINDOW_H

#include <QMainWindow>
#include <QPaintEvent>
#include <QPainter>
#include <QLinearGradient>
#include <QMouseEvent>
#include <QPoint>
#include <QToolTip>


/**
*对于给定的绘图设备（paint device，qwidget，qpixmap等），绘图时有两个坐标系：物理坐标系，逻辑坐标系。
*物理坐标系是一个真实的坐标系吗，在Qt中，其原点处于绘图设备左上角，其单位长度为绘图设备上的一像素长度，
* 其x轴向右增长，y轴向下增长。
* 逻辑坐标系是一个抽象的坐标系，其原点、单位长度没有实际意义，其x轴向下增长，y轴向右增长。
* 绘图时，图像绘制在逻辑坐标系上，再通过--视口映射、
* 事件传换将逻辑坐标系映射到物理坐标系上。进而把绘制在逻辑坐标系上的图像映射到物理坐标系上。
* 窗口基于逻辑坐标系，视口基于物理坐标系。
*
*/
class PainGradientMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    PainGradientMainWindow(QWidget *parent = 0);
    ~PainGradientMainWindow();
protected:
    void paintEvent(QPaintEvent *);
    void mouseMoveEvent(QMouseEvent *);
};

#endif // PAINGRADIENTMAINWINDOW_H
