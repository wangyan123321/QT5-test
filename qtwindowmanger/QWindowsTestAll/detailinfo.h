#ifndef DETAILINFO_H
#define DETAILINFO_H

#include <QWidget>
#include <QLabel>
#include <QComboBox>
#include <QLineEdit>
#include <QTextEdit>
#include <QGridLayout>

class detailInfo : public QWidget
{
    Q_OBJECT
public:
    explicit detailInfo(QWidget *parent = nullptr);

    QLabel *country_label;
    QLabel *province_label;
    QLabel *city_label;
    QLabel *self_desc_label;

    QComboBox *country_combox;
    QComboBox *province_combox;
    QLineEdit *city_edit;
    QTextEdit *self_desc_edit;

    QGridLayout *main_layout;

signals:

public slots:
};

#endif // DETAILINFO_H
