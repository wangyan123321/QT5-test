#ifndef STANDINPUT_H
#define STANDINPUT_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>
#include <QLabel>

class StandInput : public QWidget
{
    Q_OBJECT
public:
    explicit StandInput(QWidget *parent = nullptr);

signals:

public slots:
    void changeAge();
    void changeHigh();
private:
    QPushButton *int_input_button;
    QLineEdit *int_input_edit;
    QLabel *age_label;
    QPushButton *float_input_button;
    QLineEdit *float_input_edit;
    QLabel *high_label;
    QGridLayout *main_layout;
};

#endif // STANDINPUT_H
