#include "digiclock.h"

DigiClock::DigiClock()
{
    show_colon=true;
    QTimer *timer=new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(showtime()));

    timer->start(1000);

    showtime();
    resize(150,60);
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
void DigiClock::mousePressEvent(QMouseEvent *event){

}
void DigiClock::mouseMoveEvent(QMouseEvent *event){

}
