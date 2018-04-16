#ifndef CLOCKDIALOG_H
#define CLOCKDIALOG_H

#include "digiclock.h"

#include <QDialog>
#include <QLineEdit>
#include <QVBoxLayout>

class ClockDialog : public QDialog
{
    Q_OBJECT

public:
    ClockDialog(QWidget *parent = 0);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    ~ClockDialog();

    DigiClock *digtal;
    QVBoxLayout *main_layout;
    QLineEdit *line_edit1;
    QLineEdit *line_edit2;
    QLineEdit *line_edit3;
    QPoint drag_positon;

};

#endif // CLOCKDIALOG_H
