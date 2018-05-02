#include "imagetextmainwindow.h"

ImageTextMainWindow::ImageTextMainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("easy word test!");
    //设置窗口的中心部件
    show_widget=new ShowWidget();
    setCentralWidget(show_widget);

    setWindowIcon(QIcon("D:/Qt5/mainicon.gif"));


    //添加文本编辑工具栏
//    font_label=new QLabel(QObject::tr("00"));
    createTextEditBar();

    //创建动作
    createAction();
    //创建菜单
    createMenus();
    //创建工具栏
    createToolBar();

    //加载图片
    if(img.load("D:/Qt5/mainicon.gif")){
        show_widget->image_lable->setPixmap(QPixmap::fromImage(img));
    }
//    img.load("D:/Qt5/mainicon.gif");
//    QMovie *movie=new QMovie("D:/Qt5/mainicon.gif");
//    show_widget->image_lable->setMovie(movie);
//    movie->start();

    filename=NULL;

    //建立信号和槽的连接
    connect(font_combox,SIGNAL(activated(QString)),this,SLOT(showFontComBox(QString)));
    connect(size_combox,SIGNAL(activated(QString)),this,SLOT(showSizeSpinBox(QString)));
    connect(bold_button,SIGNAL(clicked(bool)),this,SLOT(showBoldBtn()));
    connect(italic_button,SIGNAL(clicked(bool)),this,SLOT(showItalicBtn()));
    connect(underline_button,SIGNAL(clicked(bool)),this,SLOT(showUnderLineBtn()));
    connect(color_button,SIGNAL(clicked(bool)),this,SLOT(showColorBtn()));
    connect(show_widget->text_edit,SIGNAL(currentCharFormatChanged(QTextCharFormat )),this,SLOT(showCurrentFormatChanged( QTextCharFormat )));
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

/****
 * 创建文本编辑的动作
 *
 * 文本编辑主要涉及的类
 *
 * 每个文本编辑的程序都要用到QTextEdit,QTextEdit作为文本编辑的容器
 * 在QTextEdit中的编辑的文本可由文本QTextDocument作为载体，
 * QTextBlock、QTextList、QTextFrame和QTextTable是QTextDocument的不同表现形式
 * 可以表示成字符串、段落、列表和表格或图片
 * 每种元素都有自己的格式，这些格式则用QTextCharFormat、QTextBolockFormat、QTextListFormat等类来描述。
 *
 * 文本编辑设置功能
 * 设置字体
 * 设置字号
 * 设置文字加粗
 * 设置文字斜体
 * 设置文字加下划线
 * 设置文字颜色
 *
 ****/

void ImageTextMainWindow::createTextEditBar(){
    //设置字体的选择
    font_label=new QLabel("字体");
    font_combox=new QFontComboBox();
    font_combox->setFontFilters(QFontComboBox::ScalableFonts);
    //设置字号的选择
    size_label=new QLabel("字号");
    size_combox=new QComboBox();
    QFontDatabase db;
    foreach(int size,db.standardSizes()){
        size_combox->addItem(QString::number(size));
    }
    //设置加粗按钮
    bold_button=new QToolButton();
    bold_button->setIcon(QIcon("D:/Qt5/bold.jpg"));
    bold_button->setCheckable(true);//设置字体是否会自动弹起
    //设置字体是否为斜体
    italic_button=new QToolButton();
    italic_button->setIcon(QIcon("D:/Qt5/italic.jpg"));
    italic_button->setCheckable(true);
    //设置是否加下划线
    underline_button=new QToolButton();
    underline_button->setIcon(QIcon("D:/Qt5/underline.jpg"));
    underline_button->setCheckable(true);
    //设置字体的颜色,默认是黑色
    color_button=new QToolButton();
    color_button->setIcon(QIcon("D:/Qt5/color.jpg"));
    color_button->setCheckable(true);
}
//设置字体

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

    //添加文本编辑工具栏
    text_tool_bar=addToolBar("TextEdit");
    text_tool_bar->addWidget(font_label);
    text_tool_bar->addWidget(font_combox);
    text_tool_bar->addWidget(size_label);
    text_tool_bar->addWidget(size_combox);
    text_tool_bar->addSeparator();
    text_tool_bar->addWidget(bold_button);
    text_tool_bar->addWidget(italic_button);
    text_tool_bar->addWidget(underline_button);
    text_tool_bar->addSeparator();
    text_tool_bar->addWidget(color_button);
}
/****
* 文件操作
* 主要功能包括两个，打开已有文件，新建一个文件
* 新建文件：
* 新建文件主要完成的任务是重新打开一个窗口，窗口内容为空。
* 打开已有文件：
* 通过文件选择交互窗口，选择已有的一个文件，将文件导入到编辑器中。
****/

//新建一个窗口
void ImageTextMainWindow::newfile()
{
    ImageTextMainWindow new_window=new ImageTextMainWindow();
    new_window.show();
}

//打开已有文件
//根据用户与文件对话框交互，得到用户想要的打开的文件
//查看当前编辑框中是否有文件，如果没有，则将内容加载到当前编辑框，
//如果当前编辑框存在文件，则需要新建一个文件，并且将文件内容加载到编辑器中
void ImageTextMainWindow::open()
{
    QString filename_str=QFileDialog::getOpenFileName(this,"Select Exiting Document","/");
    if(!filename_str.isEmpty()){
        if(filename&&show_widget->text_edit->document()->isEmpty()){
            loadFile(filename_str);
        }else{
            ImageTextMainWindow *new_windows=new ImageTextMainWindow();
            new_windows->loadFile(filename_str);
            new_windows->show();
        }
    }
}

void ImageTextMainWindow::loadFile(QString filename)
{
    printf("file name：%s\n",filename.data());
    this->filename=new QString(filename);
    QFile file(filename);
    if(file.open(QIODevice::ReadOnly|QIODevice::Text)){
        QTextStream textStream(&file);
        while(!textStream.atEnd()){
            show_widget->text_edit->append(textStream.readLine());
            printf("read line\n");
        }
    }
    printf("end\n");
}

/****
* Qt连接打印机流程
* 主要涉及两个类，QPrinter和QPrinterDialog
* QPrinter主要涉及打印机类，关于打印机的传输工作。
* QPrinterDialog标准打印机对话框，提供了打印机的选择、配置功能，
* 并允许使用者改变文档的有关的设置，如页面范围、打印份数。
****/
void ImageTextMainWindow::printText()
{
    QPrinter printer;
    QPrintDialog print_Dialog(&printer,this);//创建一个QPrintDialog对象，参数为QPrinter对象
    if(print_Dialog.exec()){
        //获取QLineEdit文档对象
        QTextDocument *doc=show_widget->text_edit->document();
        //打印数据
        doc->print(&printer);
    }
}
/****
 * 打印图片其实是在QPainter上画图，与平常的Qwidget、QPixmap和QImage中画图相同，
 * 都是创建一个QPainter对象进行画图，只是打印使用的是QPrintermQPrinter本质上也是
 * 一个绘图设备QPaintDevice。
 ****/
void ImageTextMainWindow::PrintImage()
{
    QPrinter printer;//新建打印机对象
    QPrintDialog print_dialog(&printer,this);//创建打印机对话框，并将打印机对象传递进去

    if(print_dialog.exec()){
        QPainter painter(&printer);//建立QPainter画板，并传递printer对象
        QRect rect=painter.viewport();//获取QPainter对象的视图矩形区域
        QSize size=img.size();//获得图像的大小

        //按照图形的大小重新设置视图的矩形区域
        size.scale(rect.size(),Qt::KeepAspectRatio);

        painter.setViewport(rect.x(),rect.y(),size.width(),size.height());
        //设置QPainter的窗口大小
        painter.setWindow(img.rect());
        //打印图像
        painter.drawImage(0,0,img);
    }
}
/****
 * QMatrix类提供了世界坐标系统的二维窗体转换功能，可以使窗体转换变形，
 * 可以实现坐标系统的移动、缩放、变形及旋转功能。
 * setScaleContents用来设置该控件的scaledContent属性，确定是否根据其大小自动调节内容大小，
 * 以使内容填充整个有效区域。
 ****/
void ImageTextMainWindow::zoomIn()
{
    if(img.isNull())
        return;
     QMatrix martix;
     martix.scale(2,2);
     img=img.transformed(martix);
     show_widget->image_lable->setPixmap(QPixmap::fromImage(img));
}

void ImageTextMainWindow::zoomOut()
{
    if(img.isNull())
        return;
     QMatrix martix;
     martix.scale(0.5,0.5);
     img=img.transformed(martix);
     show_widget->image_lable->setPixmap(QPixmap::fromImage(img));
}

void ImageTextMainWindow::rotate90()
{
    if(img.isNull())
        return;
    QMatrix matrix;
    matrix.rotate(90);
    img=img.transformed(matrix);
    show_widget->image_lable->setPixmap(QPixmap::fromImage(img));
}

void ImageTextMainWindow::rotate180()
{
    if(img.isNull())
        return;
    QMatrix matrix;
    matrix.rotate(180);
    img=img.transformed(matrix);
    show_widget->image_lable->setPixmap(QPixmap::fromImage(img));
}
void ImageTextMainWindow::rotate270()
{
    if(img.isNull())
        return;
    QMatrix matrix;
    matrix.rotate(270);
    img=img.transformed(matrix);
    show_widget->image_lable->setPixmap(QPixmap::fromImage(img));
}

void ImageTextMainWindow::mirrHorizontal()
{

    if(img.isNull())
        return;
    printf("1111\n");
    img=img.mirrored(false,true);
    show_widget->image_lable->setPixmap(QPixmap::fromImage(img));
}
void ImageTextMainWindow::mirrVertical()
{

    if(img.isNull())
        return;
    printf("2222\n");
    img=img.mirrored(true,false);
    show_widget->image_lable->setPixmap(QPixmap::fromImage(img));
}

//设定字体的槽， 当选择字体时，会调用该槽
void ImageTextMainWindow::showFontComBox(QString comboxstr)
{
    //创建文本字符的格式类
    QTextCharFormat fmt;
    //通过传过来的文本字符的命，设置所选的的字体
    fmt.setFontFamily(comboxstr);
    //调用合并操作，将字体应用到文本上
    mergeFormat(fmt);
}

//设定字体大小的槽，当选择字体大小时会调用该槽
void ImageTextMainWindow::showSizeSpinBox(QString spinValue)
{
    //创建文本字符的格式类
    QTextCharFormat fmt;
    //将传过来的文字的大小格式添加到格式类中
    fmt.setFontPointSize(spinValue.toFloat());
    //调用合并操作，将字体大小应用到文本上
    show_widget->text_edit->mergeCurrentCharFormat(fmt);
}

//设定加粗的槽，选择加粗时，调用该槽
void ImageTextMainWindow::showBoldBtn()
{
    //创建文本字体对象
    QTextCharFormat fmt;
    //查看字体加黑按钮是否被按下，如果按下设置对应的字体对象为加粗，如果没有按下设置为正常
    fmt.setFontWeight(bold_button->isChecked()?QFont::Bold:QFont::Normal);
    //将字体应用到对应的字体上
    show_widget->text_edit->mergeCurrentCharFormat(fmt);
}

//设定字体为斜体的槽，点击斜体按钮，调用该槽
void ImageTextMainWindow::showItalicBtn()
{
    //创建字体对象
    QTextCharFormat fmt;
    //根基斜体按钮是否按下，设定字体对象的状态
    fmt.setFontItalic(italic_button->isChecked());
    //将字体对象应用到文本数据上
    show_widget->text_edit->mergeCurrentCharFormat(fmt);
}

//设定斜体的槽，点击斜体的按钮，调用该槽
void ImageTextMainWindow::showUnderLineBtn()
{
    //创建字体对象
    QTextCharFormat fmt;
    //根据下划线是否被点击，设置字体的状态
    fmt.setFontUnderline(underline_button->isChecked());
    //将字体对象应用到对应的文本上
    show_widget->text_edit->mergeCurrentCharFormat(fmt);
}

//设定字体颜色的槽，点击斜体按钮，调用该槽
void ImageTextMainWindow::showColorBtn()
{
    //创建字体对象
    QTextCharFormat fmt;
    //通过颜色对话框获取颜色对象
    QColor color=QColorDialog::getColor(Qt::red,this);
    if(color.isValid()){
        //设置字体颜色的
        fmt.setForeground(color);
        //更新到文本
        show_widget->text_edit->mergeCurrentCharFormat(fmt);
    }

}

//当所处的字符格式发生变化，将调用该槽
void ImageTextMainWindow::showCurrentFormatChanged(QTextCharFormat fmt)
{
    qDebug()<<"1111";
    font_combox->setCurrentIndex(font_combox->findText(fmt.fontFamily()));
    size_combox->setCurrentIndex(size_combox->findText(QString::number(fmt.fontPointSize())));
    bold_button->setChecked(fmt.font().bold());
    italic_button->setChecked(fmt.fontItalic());
    underline_button->setChecked(fmt.fontUnderline());
    qDebug()<<"2222";
}

/****
 * 对于文本QTextDocument的修改，主要表现在对QTextCursor类的修改。
 * QTextCursor对文本的选取称作光标高亮处的文本，
 * 如果没有选取这代表光标位置后一个字符的格式修改。
 ****/
void ImageTextMainWindow::mergeFormat(QTextCharFormat format)
{
    QTextCursor cursor=show_widget->text_edit->textCursor();
   //如果光标没有选中文本，则将光标所处的词作为选区，由前后空格或','、'.'等标点符号区分词。
    if(!cursor.hasSelection()){
        cursor.select(QTextCursor::WordUnderCursor);
    }
    //将参数format所表示的格式应用到光标所处的字符上
    cursor.mergeCharFormat(format);
    //调用mergeCurrentCharFormat函数，将格式应用到所选区域的所有字符上
    show_widget->text_edit->mergeCurrentCharFormat(format);
}
void ImageTextMainWindow::copy(){

}

void ImageTextMainWindow::cut(){

}

void ImageTextMainWindow::past(){

}

void ImageTextMainWindow::about(){

}

void ImageTextMainWindow::unDo()
{

}
void ImageTextMainWindow::reDo()
{

}
