#ifndef DATAMININGWINDOW_H
#define DATAMININGWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QGridLayout>

class DataMiningWindow : public QWidget
{
    Q_OBJECT
public:
    explicit DataMiningWindow(QWidget *parent = nullptr);
    QGridLayout *main_layout;
    QLabel *test;

signals:

public slots:
};

#endif // DATAMININGWINDOW_H
