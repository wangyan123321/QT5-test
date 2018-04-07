#ifndef LAYOUTDIALOG_H
#define LAYOUTDIALOG_H

#include <QDialog>
#include <QMainWindow>

#include<QComboBox>
#include<QPushButton>

#include<QLabel>
#include<QTextEdit>
#include<QLineEdit>

#include<QGridLayout>
#include<QVBoxLayout>
#include<QHBoxLayout>

class LayoutDialog : public QDialog
{
    Q_OBJECT

public:
    LayoutDialog(QWidget *parent = 0);
    ~LayoutDialog();
private:
    //左侧
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

    //右侧
    QLabel *HeadLabel;
    QLabel *HeadIconLabel;
    QPushButton *UpdateHeadIcon;
    QLabel *IntroductionLabel;
    QTextEdit *IntroductionEdite;


    //底部
    QPushButton *OKButton;
    QPushButton *CancelButton;

    QGridLayout *LeftLayout;
    QGridLayout *MainLayout;

    QHBoxLayout *RightTopLayout;
    QVBoxLayout *RightLayout;
    QHBoxLayout *BottomLayout;

};

#endif // LAYOUTDIALOG_H
