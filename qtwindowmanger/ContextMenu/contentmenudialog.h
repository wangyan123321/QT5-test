#ifndef CONTENTMENUDIALOG_H
#define CONTENTMENUDIALOG_H

#include <QDialog>
#include <QListWidget>
#include <QLabel>
#include <QMenu>
#include <QLineEdit>
#include <QVBoxLayout>


class ContentMenuDialog : public QDialog
{
    Q_OBJECT

public:
    ContentMenuDialog(QWidget *parent = 0);
    ~ContentMenuDialog();

    QListWidget *list_widget;
    QMenu *cmenu;
    QLineEdit *line;
    QVBoxLayout *main_layout;
    QLabel *label;
public slots:
    void show_mouse_menu(QPoint point);
    void show_message();
};

#endif // CONTENTMENUDIALOG_H
