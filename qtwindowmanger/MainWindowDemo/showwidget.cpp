#include "showwidget.h"

ShowWidget::ShowWidget(QWidget *parent) : QWidget(parent)
{
    //image=new QImage();
    image_lable=new QLabel();
    text_edit=new QTextEdit();
    main_layout=new QHBoxLayout();

    this->setLayout(main_layout);

    image_lable->setScaledContents(true);

    main_layout->addWidget(image_lable);
    main_layout->addWidget(text_edit);

}
