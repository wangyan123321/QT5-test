#ifndef DIGICLOCK_H
#define DIGICLOCK_H

#include <QLCDNumber>
#include <QTime>
#include <QPoint>
#include <QTimer>
#include <QMouseEvent>
#include <QPalette>
#include <QMenu>

class DigiClock : public QLCDNumber
{
    Q_OBJECT
public:
    DigiClock();
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

public slots:
    void showtime();
    void show_mouse_menu(QPoint point);
private:
    QPoint drag_positon;
    bool show_colon;
    QMenu *cmenu;
};

#endif // DIGICLOCK_H
