#ifndef SHOWWIDGET_H
#define SHOWWIDGET_H

#include <QWidget>
#include <QImage>
#include <QTextEdit>
#include <QLabel>
#include <QHBoxLayout>

class ShowWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ShowWidget(QWidget *parent = nullptr);
    QImage *image;
    QTextEdit *text_edit;
    QLabel *image_lable;
    QHBoxLayout *main_layout;

signals:

public slots:
};

#endif // SHOWWIDGET_H
