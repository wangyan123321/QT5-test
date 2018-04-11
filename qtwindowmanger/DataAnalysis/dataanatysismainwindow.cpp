#include "dataanatysismainwindow.h"

DataAnatysisMainWindow::DataAnatysisMainWindow(QWidget *parent)
    : QMainWindow(parent)
{
//    main_splitter=new QSplitter(Qt::Horizontal,this);
//    //main_splitter->setOpaqueResize(true);

//    left_widget=new QListWidget(main_splitter);
//    left_widget->insertItem(0,QObject::trUtf8("插入数据"));
//    left_widget->insertItem(1,"数据挖掘");
//    left_widget->insertItem(2,"机器学习");
//    left_widget->insertItem(3,"帮助");
//    main_splitter->addWidget(left_widget);

    data_insert_window=new DataInsertWindow();
    data_mining_window=new DataMiningWindow();
    machine_learning_window=new MachineLearningWindow();
    help_window=new HelpWindow();

    right_stack=new QStackedWidget();
    right_stack->addWidget(data_insert_window);
    right_stack->addWidget(data_mining_window);
    right_stack->addWidget(machine_learning_window);
    right_stack->addWidget(help_window);


}

DataAnatysisMainWindow::~DataAnatysisMainWindow()
{

}
