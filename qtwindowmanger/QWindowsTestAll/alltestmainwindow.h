#ifndef ALLTESTMAINWINDOW_H
#define ALLTESTMAINWINDOW_H

#include <QFrame>
#include <QPushButton>
#include <QStackedWidget>
#include <QStack>
#include <QHBoxLayout>
#include <QListWidget>
#include <QSplitter>

#include <baseinfo.h>
#include <contactinfo.h>
#include <detailinfo.h>

/*
*创建导航页面
*导航页是整个程序的主窗口
*主要包括整体分离窗口，
*左侧的QListWidgit
*右侧的具体内容窗口Stack和两个按钮
*/

class AllTestMainWindow : public QFrame
{
    Q_OBJECT

public:
    explicit AllTestMainWindow(QWidget *parent = 0);
    ~AllTestMainWindow();

    baseInfo *base_info;
    contactInfo *contect_info;
    detailInfo *detail_info;

    QPushButton *amend_button;
    QPushButton *close_button;

    QStackedWidget *stack_window;
    QListWidget *left_list_wiget;
    QVBoxLayout *right_layout;
    QSplitter *main_window;
    QHBoxLayout *bottom_layout;
};

#endif // ALLTESTMAINWINDOW_H
