#ifndef DATAINSERTWINDOW_H
#define DATAINSERTWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QGridLayout>

class DataInsertWindow : public QWidget
{
    Q_OBJECT
public:
    explicit DataInsertWindow(QWidget *parent = nullptr);
    QGridLayout *main_layout;
    QLabel *test;

signals:

public slots:
};

#endif // DATAINSERTWINDOW_H
