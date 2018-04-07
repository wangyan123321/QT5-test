#include "layoutdialog.h"
#include <QPixmap>

LayoutDialog::LayoutDialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(QObject::tr("UserInfo"));

    MainLayout=new QGridLayout(this);//创建主布局为表格式布局
    MainLayout->setMargin(15);//设置主框架的边距，指对整个界面的边距距离
    MainLayout->setSpacing(10);//设置各个构件间的距离


    LeftLayout=new QGridLayout();//创建左侧布局，表格布局
    LeftLayout->setColumnStretch(0,1);//设置列之间的比例
    LeftLayout->setColumnStretch(1,3);
    UserNameLable=new QLabel(QObject::tr("用户名："));
    Username=new QLineEdit();
    LeftLayout->addWidget(UserNameLable,0,0);//添加对应的构件到左布局中
    LeftLayout->addWidget(Username,0,1);
    NameLable=new QLabel(QObject::tr("姓名:"));
    Name=new QLineEdit();
    LeftLayout->addWidget(NameLable,1,0);
    LeftLayout->addWidget(Name,1,1);
    SexLable=new QLabel(QObject::tr("性别"));
    Sex=new QComboBox();
    Sex->addItem(QObject::tr("1"));
    Sex->addItem(QObject::tr("2"));
    LeftLayout->addWidget(SexLable,2,0);
    LeftLayout->addWidget(Sex,2,1);
    DepartmentLable=new QLabel(QObject::tr("22:"));
    Department=new QTextEdit();
    LeftLayout->addWidget(DepartmentLable,3,0);
    LeftLayout->addWidget(Department,3,1);
    AgeLable=new QLabel(QObject::tr("11:"));
    Age=new QLineEdit();
    LeftLayout->addWidget(AgeLable,4,0);
    LeftLayout->addWidget(Age,4,1);
    OtherLable=new QLabel(QObject::tr("11:"));
    //设置控件的面板风格，由形状和阴影两部分配合决定。
    //形状包括（NoFrame，Panel，Box，HLine，Vline，Winpanel），
    //阴影包括三种（plain,Raised,Sunken）
    //OtherLable->setFrameStyle(QFrame::Panel|QFrame::Sunken);
    OtherLable->setFrameStyle(QFrame::WinPanel|QFrame::Raised);
    LeftLayout->addWidget(OtherLable,5,0,1,2);//对于一个构件如果占用多个Cell，可以通过设定横向和纵向Cell的起始和终点

    MainLayout->addLayout(LeftLayout,0,0);//将左布局放到整体布局中


    //创建右侧布局
    RightLayout=new QVBoxLayout();
    RightLayout->setMargin(10);
    RightTopLayout=new QHBoxLayout();
    HeadLabel=new QLabel(QObject::trUtf8("touxiang:"));
    HeadIconLabel=new QLabel();
    QPixmap icon("E://123.png");
    HeadIconLabel->setPixmap(icon);
    HeadIconLabel->resize(icon.width(),icon.height());
    UpdateHeadIcon=new QPushButton(trUtf8("gengxin"));
    RightTopLayout->addWidget(HeadLabel);
    RightTopLayout->addWidget(HeadIconLabel);
    RightTopLayout->addWidget(UpdateHeadIcon);
    RightLayout->addLayout(RightTopLayout);
    MainLayout->addLayout(RightLayout,0,1);
    IntroductionLabel=new QLabel("introduction:");
    IntroductionEdite=new QTextEdit();
    RightLayout->addWidget(IntroductionLabel);
    RightLayout->addWidget(IntroductionEdite);

    //创建底部布局
    BottomLayout=new QHBoxLayout();
    OKButton=new QPushButton("ok1");
    CancelButton=new QPushButton("cancel1");
    BottomLayout->addStretch();
    BottomLayout->addWidget(OKButton);
    BottomLayout->addWidget(CancelButton);
    MainLayout->addLayout(BottomLayout,1,0,1,2);
}

LayoutDialog::~LayoutDialog()
{

}
