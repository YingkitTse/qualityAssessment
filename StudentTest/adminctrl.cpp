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

adminCtrl::adminCtrl(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::adminCtrl)
{
    ui->setupUi(this);
    connect(ui->action_Exit,SIGNAL(triggered()),this,SLOT(on_exitBtn_clicked()));
    connect(ui->action_Log_out,SIGNAL(triggered()),this,SLOT(logout()));
    connect(ui->action_About_2,SIGNAL(triggered()),this,SLOT(about()));
}
void adminCtrl::Authorize(QString id, QString name, QString auth){

    xauth = auth;
    xid = id;
    xname = name;
    ui->nameLabel->setText(name);
    ui->idLabel->setText(id);
}

adminCtrl::~adminCtrl()
{
    delete ui;
}

void adminCtrl::on_exitBtn_clicked()
{
    dbase db;
    db.CloseDatabase();
    qApp->quit();
}

void adminCtrl::on_modpw_clicked()
{
    changPwDialog *dlg = new changPwDialog(this);
    dlg->show();
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
