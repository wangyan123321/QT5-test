#ifndef MACHINELEARNINGWINDOW_H
#define MACHINELEARNINGWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QGridLayout>

class MachineLearningWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MachineLearningWindow(QWidget *parent = nullptr);
    QGridLayout *main_layout;
    QLabel *test;
signals:

public slots:
};

#endif // MACHINELEARNINGWINDOW_H
