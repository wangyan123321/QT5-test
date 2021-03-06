#ifndef BASEDIALOG_H
#define BASEDIALOG_H

#include "standinput.h"

#include <QDialog>
#include <QGridLayout>
#include <QFileDialog>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>

class basedialog : public QDialog
{
    Q_OBJECT

public:
    basedialog(QWidget *parent = 0);
    ~basedialog();

public slots:
    void filenameSave();
    void filenameSelect();
    void filedirSelect();
    void filelistSelect();
    void showColor();
    void showFont();
    void showStandInput();

private:
    QGridLayout *main_layout;
    QPushButton *filename_select;
    QPushButton *filename_save;
    QPushButton *filedir_select;
    QPushButton *filelist_select;

    QLabel *filename_select_label;
    QLabel *filename_save_label;
    QLabel *filedir_select_label;
    QLabel *filelist_seslect_label;

    QLineEdit *filename_save_edit;
    QLineEdit *filename_select_edit;
    QLineEdit *filedir_select_edit;
    QTextEdit *filelist_select_edit;

    QPushButton *color_button;
    QFrame *color_frame;

    QPushButton *font_button;
    QLineEdit *font_test;

    QPushButton  *input_button;
    StandInput *standinput;


};

#endif // BASEDIALOG_H
