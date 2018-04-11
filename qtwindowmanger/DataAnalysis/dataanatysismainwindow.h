#ifndef DATAANATYSISMAINWINDOW_H
#define DATAANATYSISMAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QSplitter>
#include <QStackedWidget>

#include <datainsertwindow.h>
#include <dataminingwindow.h>
#include <machinelearningwindow.h>
#include <helpwindow.h>

class DataAnatysisMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    DataAnatysisMainWindow(QWidget *parent = 0);


    QListWidget *left_widget;
    QStackedWidget *right_stack;


    DataInsertWindow *data_insert_window;
    DataMiningWindow *data_mining_window;
    MachineLearningWindow *machine_learning_window;
    HelpWindow *help_window;

    ~DataAnatysisMainWindow();
};

#endif // DATAANATYSISMAINWINDOW_H
