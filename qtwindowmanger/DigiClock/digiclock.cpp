#include "digiclock.h"

DigiClock::DigiClock()
{

    QPalette p=palette();
    p.setColor(QPalette::Window,Qt::blue);
    setPalette(p);
    setWindowFlags(Qt::FramelessWindowHint);
    setWindowOpacity(0.5);

    show_colon=true;
    QTimer *timer=new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(showtime()));

    timer->start(1000);

    showtime();
    resize(150,60);

//    cmenu = NULL;
//    setContextMenuPolicy(Qt::CustomContextMenu);
//    connect(this,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(show_mouse_menu(QPoint)));
}
void DigiClock::showtime(){
    QTime time=QTime::currentTime();
    QString string_time=time.toString("hh:mm");

    if(show_colon){
        string_time[2]=':';
        show_colon=false;
    }else{
        string_time[2]=' ';
        show_colon=true;
    }
    display(string_time);
}
void DigiClock::show_mouse_menu(QPoint point){
    if(cmenu){
        delete cmenu;
        cmenu=NULL;
    }
    cmenu=new QMenu(this);
    cmenu->addAction("111");
    cmenu->addAction("222");

    cmenu->exec(QCursor::pos());
}
void DigiClock::mousePressEvent(QMouseEvent *event){
    if(event->button()==Qt::LeftButton){
        drag_positon=event->globalPos()-frameGeometry().topLeft();
        event->accept();
    }
}
void DigiClock::mouseMoveEvent(QMouseEvent *event){
    if(event->buttons()&Qt::LeftButton){
        move(event->globalPos()-drag_positon);
        event->accept();
    }
}
