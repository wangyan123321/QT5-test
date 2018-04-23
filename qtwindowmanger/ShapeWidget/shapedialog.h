#ifndef SHAPEDIALOG_H
#define SHAPEDIALOG_H

#include <QDialog>
#include <QMouseEvent>
#include <QPoint>
#include <QPainter>
#include <QPixmap>
#include <QBitmap>

class ShapeDialog : public QDialog
{
    Q_OBJECT

public:
    ShapeDialog(QWidget *parent = 0);
    ~ShapeDialog();

protected:
    void mouseMoveEvent(QMouseEvent *);
    void mousePressEvent(QMouseEvent *);
    void paintEvent(QPaintEvent *);
private:
    QPoint drag_position;
};

#endif // SHAPEDIALOG_H
