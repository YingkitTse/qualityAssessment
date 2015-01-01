#include "usrctrl.h"
#include "queryAssessDialog.h"
#include "modpwdialog.h"
#include "infoquerydialog.h"
#include "ui_usrctrl.h"
#include "database.h"
#include "logindialog.h"
#include <QMessageBox>

static QString xid;
static QString xauth;
static QString xname;

usrCtrl::usrCtrl(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::usrCtrl)
{
    ui->setupUi(this);
    connect(ui->action_Log_out,SIGNAL(triggered()),this,SLOT(logout()));
    connect(ui->action_Exit,SIGNAL(triggered()),this,SLOT(on_exitBtn_clicked()));
    connect(ui->action_About,SIGNAL(triggered()),this,SLOT(about()));
}

void usrCtrl::Authorize(QString id, QString name, QString auth){
    ui->nameLabel->setText(name);
    ui->idLabel->setText(id);
    xid = id;
    xauth = auth;
    xname = name;
}

usrCtrl::~usrCtrl()
{
    delete ui;
}

void usrCtrl::logout(){
    LoginDialog *dlg = new LoginDialog(0);
    dlg->show();
    this->~usrCtrl();
}

void usrCtrl::on_testBtn_clicked()
{
    queryAssessDialog *dlg = new queryAssessDialog(this);
    dlg->Authorize(xid,xname);
    dlg->show();
}

void usrCtrl::on_exitBtn_clicked()
{
    dbase db;
    db.CloseDatabase();
    qApp->quit();
}

void usrCtrl::on_modpwBtn_clicked()
{
    modPwDialog *dlg = new modPwDialog(this);
    dlg->Authorize(xauth,xid);
    dlg->show();
}

void usrCtrl::on_infoBtn_clicked()
{
    infoQueryDialog *dlg = new infoQueryDialog(this);
    dlg->Authorize(xid,xname);
    dlg->show();
}

void usrCtrl::about(){
    QMessageBox::about(this,QString::fromUtf8("关于"),
                       QString::fromUtf8("<h2>大学生综合素质测评系统 V1.0</h2>"
                                         "<p>Copyright &copy; 2014 TSE Studio."
                                         "<p>程序设计人员：（按姓氏拼音排序）"
                                         "<p>毕国康、陈贤权、谢景聪、谢英杰、杨炯建"));
}
