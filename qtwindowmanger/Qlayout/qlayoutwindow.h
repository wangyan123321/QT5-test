#ifndef QLAYOUTWINDOW_H
#define QLAYOUTWINDOW_H

#include <QMainWindow>

#include<QComboBox>
#include<QPushButton>

#include<QLabel>
#include<QTextEdit>
#include<QLineEdit>
//三种布局管理器
#include<QGridLayout>
#include<QVBoxLayout>
#include<QHBoxLayout>


/*
*通过实现一个“用户基本的资料修改”的功能表，来介绍如何使用基本的布局管理。
*本实例用到四个布局管理器分别是LeftLayout，RightLayout，BottomLayout和MainLayout
*
*/
class QLayoutWindow : public QMainWindow
{
    Q_OBJECT

public:
    QLayoutWindow(QWidget *parent = 0);
    ~QLayoutWindow();
private:
    QLabel *UserNameLable;
    QLabel *NameLable;
    QLabel *SexLable;
    QLabel *DepartmentLable;
    QLabel *AgeLable;
    QLabel *OtherLable;

    QLineEdit *Username;
    QLineEdit *Name;
    QTextEdit *Department;
    QLineEdit *Age;
    QComboBox *Sex;
    QLineEdit *Other;

    QGridLayout *LeftLayout;
    QGridLayout *MainLayout;

};

#endif // QLAYOUTWINDOW_H
