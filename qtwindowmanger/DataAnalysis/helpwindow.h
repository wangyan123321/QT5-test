#ifndef HELPWINDOW_H
#define HELPWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QGridLayout>

class HelpWindow : public QWidget
{
    Q_OBJECT
public:
    explicit HelpWindow(QWidget *parent = nullptr);
    QGridLayout *main_layout;
    QLabel *test;
signals:

public slots:
};

#endif // HELPWINDOW_H
