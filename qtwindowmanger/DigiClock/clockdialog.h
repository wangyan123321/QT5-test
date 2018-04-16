#ifndef CLOCKDIALOG_H
#define CLOCKDIALOG_H

#include <QDialog>

class ClockDialog : public QDialog
{
    Q_OBJECT

public:
    ClockDialog(QWidget *parent = 0);
    ~ClockDialog();
};

#endif // CLOCKDIALOG_H
