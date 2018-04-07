#ifndef BASEINFO_H
#define BASEINFO_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QComboBox>
#include <QPushButton>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>

class baseInfo : public QWidget
{
    Q_OBJECT
public:
    explicit baseInfo(QWidget *parent = nullptr);

    QLabel *user_name;
    QLineEdit *user_name_edit;
    QLabel *name;
    QLineEdit *name_edit;
    QLabel *sex;
    QComboBox *sex_select;
    QLabel *department;
    QTextEdit *department_edit;
    QLabel *age;
    QLineEdit *age_edit;
    QLabel *other;
    QLabel *head;
    QLabel *head_icon;
    QPushButton *head_update;
    QLabel *self_introduction;
    QTextEdit *self_introduction_edit;

    QGridLayout *left_layout;
    QVBoxLayout *right_layout;
    QGridLayout *main_layout;

signals:

public slots:
};

#endif // BASEINFO_H
