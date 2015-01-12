#include "adminctrl.h"
#include "ui_adminctrl.h"
#include "changpwdialog.h"
#include "modassesdialog.h"
#include "syssetdialog.h"
#include "infomoddialog.h"
#include "logindialog.h"
#include "database.h"

static QString xauth;
static QString xid;
static QString xname;
/* 新建全局变量xauth，xid，xname记录由登录窗口传递的用户权限，登录名，姓名的值 */


adminCtrl::adminCtrl(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::adminCtrl)
{
    ui->setupUi(this);
    connect(ui->action_Exit,SIGNAL(triggered()),this,SLOT(on_exitBtn_clicked()));
    connect(ui->action_Log_out,SIGNAL(triggered()),this,SLOT(logout()));
    connect(ui->action_About_2,SIGNAL(triggered()),this,SLOT(about()));
}
/* 管理员主窗口的构造函数。
 * 此函数在窗口产生时调用。
 * 输入参数：QWidget类指针对象”父窗体“
 * 继承自：QMainWindow类父窗体，命名空间ui。
 * 在构造函数中手动连接：窗口控件的SIGNAL（信号）和目标的SLOT（槽，即相应动作）
 */

void adminCtrl::Authorize(QString id, QString name, QString auth){

    xauth = auth;
    xid = id;
    xname = name;
    ui->nameLabel->setText(name);
    ui->idLabel->setText(id);
}
/* Authorize函数
 * 输入参数：用户名id，姓名name，权限auth
 * 把输入参数赋值到全局变量
 * 调用此函数时，把窗体中的空间Label调用setText函数设定为指定文字
 */

adminCtrl::~adminCtrl()//析构函数
{
    delete ui;
}

void adminCtrl::on_exitBtn_clicked() //退出按钮按下的动作
{
    dbase db;//新建dbase类对象db
    db.CloseDatabase();//调用db对象的CloseDatabase函数关闭数据库连接
    qApp->quit();//告知主程序退出，终止进程。
}

void adminCtrl::on_modpw_clicked()//修改密码按钮的按下的动作
{
    changPwDialog *dlg = new changPwDialog(this);//新建changePwDialog类窗口指针对象dlg，父窗体是本窗口（this）
    dlg->show();//显示窗口
}

void adminCtrl::on_testBtn_clicked()
{
    modAssesDialog *dlg = new modAssesDialog(this);
    dlg->show();
}

void adminCtrl::on_infoBtn_clicked()
{
    infoModDialog *dlg = new infoModDialog(this);
    dlg->show();
}

void adminCtrl::on_sysBtn_clicked()
{
    sysSetDialog *dlg = new sysSetDialog(this);
    dlg->show();
}

void adminCtrl::logout(){
    LoginDialog *dlg = new LoginDialog(0);
    dlg->show();
    this->~adminCtrl();
}

void adminCtrl::about(){
    QMessageBox::about(this,QString::fromUtf8("关于"),
                       QString::fromUtf8("<h2>大学生综合素质测评系统 V1.0</h2>"
                                         "<p>Copyright &copy; 2014 TSE Studio."
                                         "<p>程序设计人员：（按姓氏拼音排序）"
                                         "<p>毕国康、陈贤权、谢景聪、谢英杰、杨炯建"));
}
/* 使用QMessageBox类弹出about关于对话框
 * 父窗体：this，本窗口
 * 标题：关于
 */
