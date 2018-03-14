#include "mainwindow.h"

#include <QApplication>
#include <QSplitter>
#include <QTextEdit>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

    QFont font("ZYSong18030",12);//设置显示的字体
    a.setFont(font);

    QSplitter *splitter=new QSplitter(Qt::Horizontal,0);//创建分割窗口，设置本分个窗口是水平分割窗口
    QTextEdit *textLeft=new QTextEdit(QObject::tr("left text!!!"),splitter);//设置文本的内容
    textLeft->setAlignment(Qt::AlignCenter);//设置文本的对齐方式

    QSplitter *rightSplitter=new QSplitter(Qt::Vertical,splitter);//设置右窗口的分割方式，并且设置他的主窗口
    rightSplitter->setOpaqueResize(false);//设置拖拉时是否实时显示
    QTextEdit *textRight1=new QTextEdit(QObject::tr("Right 1 text!!!"),rightSplitter);//设置文本的内容
    textRight1->setAlignment(Qt::AlignCenter);
    QTextEdit *textRight2=new QTextEdit(QObject::tr("Right 2 text!!!"),rightSplitter);//设置文本的内容
    textRight2->setAlignment(Qt::AlignBottom);

    /*用于设定可伸缩控件
     *第一个参数表示控件的序号，对于一个窗口来说，每个控件对应一个序号，
     * 序号从0开始计数
     * 第二个参数表示控件是否具有可伸缩性，是一个大于0的值
     */
    splitter->setStretchFactor(1,1);

    splitter->setWindowTitle(QObject::tr("splitter"));
    splitter->show();

    return a.exec();
}
