#ifndef STACKDIALOG_H
#define STACKDIALOG_H

#include <QDialog>
#include <QListWidget>
#include <QLabel>
#include <QStackedWidget>
#include <QDockWidget>

class stackDialog : public QDialog
{
    Q_OBJECT

public:
    stackDialog(QWidget *parent = 0);
    ~stackDialog();
private:
    QListWidget *listwidget;
    QStackedWidget *stackwiget;
    QLabel *lable1;
    QLabel *lable2;
    QLabel *lable3;
    QDockWidget *dock1;
    QDockWidget *dock2;
    QDockWidget *dock3;

};

#endif // STACKDIALOG_H
