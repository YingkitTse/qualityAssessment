#include "logindialog.h"
#include "ui_logindialog.h"
#include "_Glo.h"
#include <QMessageBox>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_loginBtn_clicked()
{
    QSqlQuery query;
    QString passwd, xpasswd;
    QString usrname = ui->usrLineEdit->text();
    query.prepare("select pw,auth FROM userInfo WHERE id= :xid");
    query.bindValue(":xid",usrname);
    query.exec();
    if(!query.isActive()){
        QMessageBox::warning(this,tr("Database Error"),query.lastError().text(),QMessageBox::Ok);
    }
    if(query.next()){
        passwd = query.value(0).toString();
        xpasswd = ui->pwLineEdit->text();
        if( QString::compare(passwd,xpasswd,Qt::CaseInsensitive) ) {//研究compare函数，确认if条件，此处条件不正确!
            int auth = query.value(1).toInt();
            switch(auth){
            case 0: QMessageBox::warning(this,tr("Auth"),tr("Class 0"),QMessageBox::Ok);_Glo_Class=0;break;
            case 1: QMessageBox::warning(this,tr("Auth"),tr("Class 1"),QMessageBox::Ok);_Glo_Class=1;break;
            case 2: QMessageBox::warning(this,tr("Auth"),tr("Class 2"),QMessageBox::Ok);_Glo_Class=2;break;
            };
            accept();
        }
    }
    else {
        QMessageBox::warning(this, tr("Warning"), tr("UserName or Password Error!"),QMessageBox::Yes);
    }

    ui->usrLineEdit->clear();
    ui->pwLineEdit->clear();
    ui->usrLineEdit->setFocus();
}
