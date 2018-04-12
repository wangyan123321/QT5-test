#ifndef QTOOLBOXWIDGET_H
#define QTOOLBOXWIDGET_H

#include <QWidget>
#include <QListWidget>
#include <QToolBox>
#include <QGroupBox>
#include <QGridLayout>

/*
*qt下工具箱的设置
*工具箱主要由QToolBox类完成
*需要用到QGroupBox类似于抽屉的一个匣子
*还可以使用布局填充QGroupBox，在布局中添加对应的控件
*/
class QToolBoxWidget : public QWidget
{
    Q_OBJECT

public:
    QToolBoxWidget(QWidget *parent = 0);
    ~QToolBoxWidget();
    QListWidget *qlist1;
    QListWidget *qlist2;
    QListWidget *qlist3;

    QToolBox *tool_box_1;
    QToolBox *tool_box_2;

    QGroupBox *group_box1;
    QGroupBox *group_box2;

    QGridLayout *main_layout;
};

#endif // QTOOLBOXWIDGET_H
