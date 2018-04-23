#ifndef EXTENSIONDIALOG_H
#define EXTENSIONDIALOG_H

#include <QDialog>
#include <QWidget>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>

/**
*实现隐藏窗体
*具体分为两个部分一个是基础窗体，一个是隐藏窗体
*具体窗体任何人都能看到，隐藏窗体需要特殊权限或者特殊需求
**/
class ExtensionDialog : public QDialog
{
    Q_OBJECT

public:
    ExtensionDialog(QWidget *parent = 0);
    ~ExtensionDialog();
public slots:
    void showDetailInfo();
public:
    void creatBaseInfo();
    void creatDetailInfo();

    QWidget *base_info;
    QWidget *detail_info;

    QVBoxLayout *main_layout;

};

#endif // EXTENSIONDIALOG_H
