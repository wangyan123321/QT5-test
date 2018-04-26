#ifndef IMAGETEXTMAINWINDOW_H
#define IMAGETEXTMAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QAction>
#include <QComboBox>
#include <QSpinBox>
#include <QToolBar>
#include <QFontComboBox>
#include <QToolButton>
#include <QTextCharFormat>
#include <QIcon>
#include <QMenuBar>
#include <QMovie>

/***
 * 本实例主要熟悉QMainWindow的整体架构
 * 包括菜单栏，工具栏，锚接部件区，状态栏和中心部件
 * 菜单是一系列命令的列表。
 * 状态栏主要显示应用程序的一些状态信息。
 * 工具栏是有一些类似于按钮的动作排列而成的面板，通常是由一些动作和命令组成。
 * 锚接部件作为一个容器使用，以包容其他窗口部件来实现某些功能。
 * 中心部件是位于主窗口的中心，可以实现需要的布局管理器
 *
 *
 * ImageTextMainWindiow主要是完成一些文本和图像的操作
 * 文本操作包括字体，大小等操作
 * 图像操作包括图像的放大，缩小，旋转等
 *
 * 主要熟悉主窗口的各个组件的的使用方式
 ***/
#include <showwidget.h>
class ImageTextMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    ImageTextMainWindow(QWidget *parent = 0);
    ~ImageTextMainWindow();

    void createAction();
    void createMenus();
    void createToolBar();
    void loadFile(QString filename);
    void mergeFormat(QTextCharFormat);

private:
    //各项菜单栏
    QMenu *file_menu;
    QMenu *zoom_menu;
    QMenu *rotate_menu;
    QMenu *mirror_menu;
    QImage img;
    QMovie img1;
    QString filename;
    ShowWidget *show_widget;
    //文件菜单
    QAction *open_file_action;
    QAction *new_file_action;
    QAction *print_text_action;
    QAction *print_image_action;
    QAction *exit_action;
    //编辑菜单
    QAction *copy_action;
    QAction *cut_action;
    QAction *paste_action;
    QAction *about_action;
    QAction *zoom_in_action;
    QAction *zoom_out_action;
    //旋转菜单
    QAction *rotate_90_action;
    QAction *rotate_180_action;
    QAction *rotate_270_action;
    //镜像菜单
    QAction *mirr_vertical_action;
    QAction *mirr_horizontal_action;
    QAction *undo_action;
    QAction *redo_action;
    //工具栏
    QToolBar *file_tool;
    QToolBar *zoom_tool;
    QToolBar *rotate_tool;
    QToolBar *mirror_tool;
    QToolBar *do_tool_bar;

public slots:
    void open();
    void newfile();
    void copy();
    void cut();
    void past();
    void about();
    void printText();
    void PrintImage();
    void zoomIn();
    void zoomOut();

    void rotate90();
    void rotate180();
    void rotate270();

    void mirrHorizontal();
    void mirrVertical();

    void unDo();
    void reDo();
};

#endif // IMAGETEXTMAINWINDOW_H
