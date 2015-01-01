#include "logindialog.h"
#include "adminctrl.h"
#include "usrctrl.h"
#include "teactrl.h"
#include "ui_logindialog.h"
#include "dbquery.h"
#include "database.h"
#include <QtSql>
#include <QMessageBox>

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    ui->StuCheckBox->setChecked(true);
    ui->TeaCheckBox->setChecked(false);
    ui->AdminCheckBox->setChecked(false);
    ui->usrLineEdit->setFocus();
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_exitBtn_clicked()
{
    dbase db;
    db.CloseDatabase();
    reject();
}

void LoginDialog::on_loginBtn_clicked()
{
    dbquery db;
    QString usrline = ui->usrLineEdit->text();
    QString pwline = ui->pswLineEdit->text();
    if( usrline.isEmpty() || pwline.isEmpty() ){
        QMessageBox::warning(this,QString::fromUtf8("警告"),QString::fromUtf8("用户名或密码不能为空！\n请重新输入！"),QMessageBox::Ok);
        ui->usrLineEdit->setFocus();
    }
    else{
        if ( ui->StuCheckBox->isChecked() ){
            if ( db.Authenticated(usrline.trimmed(),pwline,qApp->tr("0")) ){
                QMessageBox::information(this,QString::fromUtf8("提示"),QString::fromUtf8("登录成功！\n您好，%1\n您现在的登录身份为学生").arg(db.queryName(usrline)),QMessageBox::Ok);
                usrCtrl* win = new usrCtrl(0);
                win->Authorize(usrline,db.queryName(usrline),qApp->tr("0"));
                win->show();
                this->close();
              }
            else{
                QMessageBox::warning(this,QString::fromUtf8("错误"),QString::fromUtf8("用户名或密码错误！\n请检查您的密码！"),QMessageBox::Abort);
                ui->pswLineEdit->clear();
                ui->usrLineEdit->clear();
                ui->usrLineEdit->setFocus();
                return;
              }
          }
        else if( ui->TeaCheckBox->isChecked() ){
            if( db.Authenticated(usrline.trimmed(),pwline,qApp->tr("1")) ){
                QMessageBox::information(this,QString::fromUtf8("提示"),QString::fromUtf8("登录成功！\n您好，%1\n您现在的登录身份为教职工").arg(db.queryName(usrline)),QMessageBox::Ok);
                teaCtrl *win = new teaCtrl(0);
                win->Authorize(usrline,db.queryName(usrline),qApp->tr("1"));
                win->show();
                this->close();
              }
            else{
                QMessageBox::warning(this,QString::fromUtf8("错误"),QString::fromUtf8("用户名或密码错误！\n请检查您的密码！"),QMessageBox::Abort);
                ui->pswLineEdit->clear();
                ui->usrLineEdit->clear();
                ui->usrLineEdit->setFocus();
                return;
              }
          }
        else if (ui->AdminCheckBox->isChecked()){
            if (db.Authenticated(usrline.trimmed(),pwline,qApp->tr("2"))){
                QMessageBox::information(this,QString::fromUtf8("提示"),QString::fromUtf8("登录成功！\n您好，%1\n您现在的登录身份为管理员").arg(db.queryName(usrline)),QMessageBox::Ok);
                adminCtrl* win = new adminCtrl(0);
                win->Authorize(usrline,db.queryName(usrline),qApp->tr("2"));
                win->show();
                this->close();
              }
            else{
                QMessageBox::warning(this,QString::fromUtf8("错误"),QString::fromUtf8("用户名或密码错误！\n请检查您的密码！"),QMessageBox::Abort);
                ui->pswLineEdit->clear();
                ui->usrLineEdit->clear();
                ui->usrLineEdit->setFocus();
                return;
              }
          }
      }
}
