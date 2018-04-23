#ifndef PAINTEWIDGET_H
#define PAINTEWIDGET_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>

class PainteWidget : public QWidget
{
    Q_OBJECT

public:
    PainteWidget(QWidget *parent = 0);
    ~PainteWidget();
protected:
    void paintEvent(QPaintEvent *);
};

#endif // PAINTEWIDGET_H
