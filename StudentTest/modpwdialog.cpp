#include "modpwdialog.h"
#include "dbquery.h"
#include "ui_modpwdialog.h"
#include <QMessageBox>
#include <QString>

static QString xid;
static QString xauth;

modPwDialog::modPwDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modPwDialog)
{
    ui->setupUi(this);
    ui->oldPwErrTip->hide();
    ui->rpPwErrTip->hide();
}

void modPwDialog::Authorize(QString auth, QString id){
  dbquery db;
  ui->idLabel->setText(id);
  ui->nameLabel->setText(db.queryName(id));
  xid = id;
  xauth = auth;
}

modPwDialog::~modPwDialog()
{
    delete ui;
}

void modPwDialog::on_OkBtn_clicked()
{
    dbquery db;
    QString oldpw = ui->oldPwLineEdit->text();
    QString newpw = ui->newPwLineEdit->text();
    QString rppw = ui->rpPwLineEdit->text();
    if (ui->oldPwLineEdit->text().isEmpty()){
        QMessageBox::information(this,QString::fromUtf8("错误"),QString::fromUtf8("旧密码不能为空！\n请重新输入！"),QMessageBox::Ok);
        ui->oldPwLineEdit->setFocus();
    }
    else if( newpw.operator !=(rppw) ){
        ui->rpPwErrTip->show();
        ui->newPwLineEdit->clear();
        ui->rpPwLineEdit->clear();
        ui->newPwLineEdit->setFocus();
    }
    else if( !db.Authenticated(xid,oldpw,xauth) ){
        ui->oldPwErrTip->show();
        ui->oldPwLineEdit->clear();
        ui->oldPwLineEdit->setFocus();
    }
    else{
        if(db.modPw(xid,newpw)){
            QMessageBox::information(this,QString::fromUtf8("提示"),QString::fromUtf8("修改密码成功！"),QMessageBox::Ok);
        }
        else QMessageBox::critical(this,QString::fromUtf8("错误"),QString::fromUtf8("未知原因错误！\n请与数据库管理员联系！"),QMessageBox::Ok);
        ui->oldPwLineEdit->setFocus();
    }
}

void modPwDialog::on_cancelBtn_clicked()
{
    this->close();
}
