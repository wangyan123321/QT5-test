#ifndef CONTACTINFO_H
#define CONTACTINFO_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QGridLayout>

class contactInfo : public QWidget
{
    Q_OBJECT
public:
    explicit contactInfo(QWidget *parent = nullptr);

    QLabel *email_label;
    QLineEdit *email_edit;
    QLabel *address_label;
    QLineEdit *address_edit;
    QLabel *mailnum_label;
    QLineEdit *mailnum_edit;
    QLabel *movble_phone_num_label;
    QLineEdit *movble_phone_num_edit;
    QCheckBox *leave_say;
    QGridLayout *main_layout;

signals:

public slots:
};

#endif // CONTACTINFO_H
