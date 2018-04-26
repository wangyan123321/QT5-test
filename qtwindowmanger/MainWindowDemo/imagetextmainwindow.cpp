#include "imagetextmainwindow.h"

ImageTextMainWindow::ImageTextMainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("easy word test!");
    //设置窗口的中心部件
    show_widget=new ShowWidget();
    setCentralWidget(show_widget);

    setWindowIcon(QIcon("D:/Qt5/mainicon.gif"));



    //创建动作
    createAction();
    //创建菜单
    createMenus();
    //创建工具栏
    createToolBar();

    //加载图片
//    if(img.load("D:/Qt5/plant.jpg")){
//        show_widget->image_lable->setPixmap(QPixmap::fromImage(img));
//    }
    QMovie *movie=new QMovie("D:/Qt5/mainicon.gif");
    show_widget->image_lable->setMovie(movie);
    movie->start();
}

ImageTextMainWindow::~ImageTextMainWindow()
{

}
/****
 *
 * 创建相应的动作，使得菜单中的选项条目，工具栏上的功能按钮和快捷键能够触发相同的动作
 * QAction包含了图标、菜单文字、快捷键、状态栏文字、浮动帮助等信息。
 * QAction可以作为一个菜单项，一个工具栏按钮，当用户点击按钮时可以执行相应的动作。
 * Qt没有专门的菜单类项，只是使用一个QAction类，抽象出动作，当我们对象添加到菜单，就显示菜单项，添加到工具栏就显示成一个工具按钮。
 * Qt能够保证把QAction对象添加到不同的菜单、工具栏时、显示内容是同步的，一旦修改了QAction的图标，
 * 菜单和工具栏中的图标同步修改。
 *
 * 图标需求：
 * 打开文件图标，新建图标，复制图标，剪切图标，粘贴图标，
 * 打印文本图标，打印图像图标，放大图标，缩小图标，
 * 旋转图标90，旋转图标180，旋转图标270
 ****/
void ImageTextMainWindow::createAction()
{
    //打开文件操作
    open_file_action=new QAction(QIcon("D:/Qt5/open.jpg"),"open",this);//添加动作，动作包括图标，名称，父类
    open_file_action->setShortcut(QObject::tr("Ctrl+O"));//添加快捷键功能
    open_file_action->setStatusTip("open a files");//状态栏中添加显示消息
    connect(open_file_action,SIGNAL(triggered(bool)),this,SLOT(open()));//设置触发方式
    //新建文件动作
    new_file_action=new QAction(QIcon("D:/Qt5/new.jpg"),"New file",this);
    new_file_action->setShortcut(QObject::tr("Ctrl+N"));
    new_file_action->setStatusTip("new a file");
    connect(new_file_action,SIGNAL(triggered(bool)),this,SLOT(newfile()));
    //打印文本
    print_text_action=new QAction(QIcon("D:/Qt5/printtext.jpg"),"Print Text",this);
    print_text_action->setShortcut(QObject::tr("Ctrl+P+T"));
    print_text_action->setStatusTip("Print text");
    connect(print_text_action,SIGNAL(triggered(bool)),this,SLOT(printText()));
    //打印图片
    print_image_action=new QAction(QIcon("D:/Qt5/printimage.jpg"),"Print Image",this);
    print_image_action->setShortcut(QObject::tr("Ctrl+P+I"));
    print_image_action->setStatusTip("Print Image");
    connect(print_image_action,SIGNAL(triggered(bool)),this,SLOT(PrintImage()));
    //退出
    exit_action=new QAction("Exit",this);
    exit_action->setShortcut(QObject::tr("Ctrl+Q"));
    exit_action->setStatusTip("Exit");
    connect(exit_action,SIGNAL(triggered(bool)),this,SLOT(close()));
    //复制动作
    copy_action=new QAction(QIcon("D:/Qt5/copy.jpg"),"Copy",this);
    copy_action->setShortcut(QObject::tr("Ctrl+C"));
    copy_action->setStatusTip("Copy file");
    connect(copy_action,SIGNAL(triggered(bool)),this,SLOT(copy()));
    //剪切动作
    cut_action=new QAction(QIcon("D:/Qt5/cut.jpg"),"Cut",this);
    cut_action->setShortcut(QObject::tr("Ctrl+X"));
    cut_action->setStatusTip("Cut file");
    connect(cut_action,SIGNAL(triggered(bool)),this,SLOT(cut()));
    //粘贴动作
    paste_action=new QAction(QIcon("D:/Qt5/paste.jpg"),"Paste",this);
    paste_action->setShortcut(QObject::tr("Ctrl+V"));
    paste_action->setStatusTip("Paste file");
    connect(paste_action,SIGNAL(triggered(bool)),this,SLOT(past()));
    //关于动作
    about_action=new QAction("About",this);
    connect(about_action,SIGNAL(triggered(bool)),this,SLOT(about()));
    //图片放大动作
    zoom_in_action=new QAction(QIcon("D:/Qt5/zoomin.jpg"),"Zoom In",this);
    zoom_in_action->setShortcut(QObject::tr("Ctrl+I"));
    zoom_in_action->setStatusTip("Zoom In");
    connect(zoom_in_action,SIGNAL(triggered(bool)),this,SLOT(zoomIn()));
    //图片缩小动作
    zoom_out_action=new QAction(QIcon("D:/Qt5/zoomout.jpg"),"Zoom Out",this);
    zoom_out_action->setShortcut(QObject::tr("Ctrl+O"));
    zoom_out_action->setStatusTip("Zoom Out");
    connect(zoom_out_action,SIGNAL(triggered(bool)),this,SLOT(zoomOut()));
    //实现图像旋转工作
    //顺时针旋转90度
    rotate_90_action=new QAction(QIcon("D:/Qt5/romate90.jpg"),"rotate 90",this);
    rotate_90_action->setStatusTip("Rotate 90");
    connect(rotate_90_action,SIGNAL(triggered(bool)),this,SLOT(rotate90()));
    //顺时针旋转180度
    rotate_180_action=new QAction(QIcon("D:/Qt5/romate180.jpg"),"rotate 180",this);
    rotate_180_action->setStatusTip("Rotate 180");
    connect(rotate_180_action,SIGNAL(triggered(bool)),this,SLOT(rotate180()));
    //顺时针旋转270度
    rotate_270_action=new QAction(QIcon("D:/Qt5/romate270.jpg"),"rotate 270",this);
    rotate_270_action->setStatusTip("Rotate 270");
    connect(rotate_270_action,SIGNAL(triggered(bool)),this,SLOT(rotate270()));
    //实现图像镜像动作
    //纵向镜像
    mirr_vertical_action=new QAction(QIcon("D:/Qt5/mirrorvertical.jpg"),"Mirror Vertical",this);
    mirr_vertical_action->setStatusTip("Mirroe Vertical");
    connect(mirr_vertical_action,SIGNAL(triggered(bool)),this,SLOT(mirrVertical()));
    //横向镜像
    mirr_horizontal_action=new QAction(QIcon("D:/Qt5/mirrorhorizontal.jpg"),"Mirror Horizontal",this);
    mirr_horizontal_action->setStatusTip("Mirror Horizantal");
    connect(mirr_horizontal_action,SIGNAL(triggered(bool)),this,SLOT(mirrHorizontal()));
    //实现恢复和撤销动作
    //撤销动作
    undo_action=new QAction(QIcon("D:/Qt5/undo.jpg"),"Undo",this);
    undo_action->setStatusTip("Un Do It");
    connect(undo_action,SIGNAL(triggered(bool)),this,SLOT(unDo()));
    //重做动作
    redo_action=new QAction(QIcon("D:/Qt5/redo.jpg"),"Redo",this);
    undo_action->setStatusTip("Redo");
    connect(redo_action,SIGNAL(triggered(bool)),this,SLOT(reDo()));
}
void ImageTextMainWindow::createMenus()
{
    //文件菜单
    file_menu=this->menuBar()->addMenu("File");//菜单栏添加文件菜单
    file_menu->addAction(open_file_action);//向菜单栏中添加动作
    file_menu->addAction(new_file_action);
    file_menu->addAction(print_text_action);
    file_menu->addAction(print_image_action);
    file_menu->addSeparator();
    file_menu->addAction(exit_action);
    //缩放菜单
    zoom_menu=this->menuBar()->addMenu("Edit");
    zoom_menu->addAction(copy_action);
    zoom_menu->addAction(cut_action);
    zoom_menu->addAction(paste_action);
    zoom_menu->addAction(about_action);
    zoom_menu->addSeparator();
    zoom_menu->addAction(zoom_in_action);
    zoom_menu->addAction(zoom_out_action);
    //旋转菜单
    rotate_menu=this->menuBar()->addMenu("Rotate");
    rotate_menu->addAction(rotate_90_action);
    rotate_menu->addAction(rotate_180_action);
    rotate_menu->addAction(rotate_270_action);
    //镜像菜单
    mirror_menu=this->menuBar()->addMenu("Mirror");
    mirror_menu->addAction(mirr_vertical_action);
    mirror_menu->addAction(mirr_horizontal_action);

}

void ImageTextMainWindow::createToolBar()
{
    //文件工具栏
    file_tool=addToolBar("File");//工具栏添加文件工具栏
    file_tool->addAction(open_file_action);//工具栏中添加动作
    file_tool->addAction(new_file_action);
    file_tool->addAction(print_text_action);
    file_tool->addAction(print_image_action);
    //编辑工具栏
    zoom_tool=addToolBar("Edit");
    zoom_tool->addAction(copy_action);
    zoom_tool->addAction(cut_action);
    zoom_tool->addAction(paste_action);
    zoom_tool->addAction(about_action);
    zoom_tool->addSeparator();
    zoom_tool->addAction(zoom_in_action);
    zoom_tool->addAction(zoom_out_action);
    //旋转工具栏
    rotate_tool=addToolBar("Rotate");
    rotate_tool->addAction(rotate_90_action);
    rotate_tool->addAction(rotate_180_action);
    rotate_tool->addAction(rotate_270_action);
    //镜像工具栏
    mirror_tool=addToolBar("Mirror");
    mirror_tool->addAction(mirr_vertical_action);
    mirror_tool->addAction(mirr_horizontal_action);

    do_tool_bar=addToolBar("Redo or Undo");
    do_tool_bar->addAction(undo_action);
    do_tool_bar->addAction(redo_action);
}

void ImageTextMainWindow::open()
{

}

void ImageTextMainWindow::newfile()
{

}

void ImageTextMainWindow::loadFile(QString filename)
{

}

void ImageTextMainWindow::mergeFormat(QTextCharFormat)
{

}
void ImageTextMainWindow::copy(){

}

void ImageTextMainWindow::cut(){

}

void ImageTextMainWindow::past(){

}

void ImageTextMainWindow::about(){

}

void ImageTextMainWindow::printText()
{

}

void ImageTextMainWindow::PrintImage()
{

}

void ImageTextMainWindow::zoomIn()
{

}

void ImageTextMainWindow::zoomOut()
{

}
void ImageTextMainWindow::rotate90()
{

}
void ImageTextMainWindow::rotate180()
{

}
void ImageTextMainWindow::rotate270()
{

}
void ImageTextMainWindow::mirrHorizontal()
{

}
void ImageTextMainWindow::mirrVertical()
{

}
void ImageTextMainWindow::unDo()
{

}
void ImageTextMainWindow::reDo()
{

}
