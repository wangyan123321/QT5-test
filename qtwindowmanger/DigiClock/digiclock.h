#ifndef DIGICLOCK_H
#define DIGICLOCK_H

#include <QLCDNumber>
#include <QTime>
#include <QPoint>
#include <QTimer>
#include <QMouseEvent>
#include <QPalette>

class DigiClock : public QLCDNumber
{
    Q_OBJECT
public:
    DigiClock();
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
public slots:
    void showtime();
private:
    QPoint drag_positon;
    bool show_colon;
};

#endif // DIGICLOCK_H
