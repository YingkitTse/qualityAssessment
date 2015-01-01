#include "teactrl.h"
#include "ui_teactrl.h"
#include "modassesdialog.h"
#include "infomoddialog.h"
#include "changpwdialog.h"
#include "logindialog.h"
#include "database.h"

static QString xid;
static QString xauth;
static QString xname;

teaCtrl::teaCtrl(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::teaCtrl)
{
    ui->setupUi(this);
    connect(ui->action_Log_out,SIGNAL(triggered()),this,SLOT(logout()));
    connect(ui->action_Exit,SIGNAL(triggered()),this,SLOT(on_exitBtn_clicked()));
    connect(ui->action_About,SIGNAL(triggered()),this,SLOT(about()));
}

void teaCtrl::Authorize(QString id, QString name, QString auth){
    xid = id;
    xauth = auth;
    xname = name;
    ui->nameLabel->setText(xname);
    ui->idLabel->setText(xid);
}

teaCtrl::~teaCtrl()
{
    delete ui;
}

void teaCtrl::on_testBtn_clicked()
{
    modAssesDialog *dlg = new modAssesDialog(this);
    dlg->show();
}

void teaCtrl::on_infoBtn_clicked()
{
    infoModDialog *dlg = new infoModDialog(this);
    dlg->show();
}

void teaCtrl::on_pwBtn_clicked()
{
    changPwDialog *dlg = new changPwDialog(this);
    dlg->show();
}

void teaCtrl::on_exitBtn_clicked()
{
    dbase db;
    db.CloseDatabase();
    qApp->quit();
}

void teaCtrl::logout(){
    LoginDialog *dlg = new LoginDialog(0);
    dlg->show();
    this->~teaCtrl();
}

void teaCtrl::about(){
    QMessageBox::about(this,QString::fromUtf8("关于"),
                       QString::fromUtf8("<h2>大学生综合素质测评系统 V1.0</h2>"
                                         "<p>Copyright &copy; 2014 TSE Studio."
                                         "<p>程序设计人员：（按姓氏拼音排序）"
                                         "<p>毕国康、陈贤权、谢景聪、谢英杰、杨炯建"));
}
