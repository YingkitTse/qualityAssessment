#include "changpwdialog.h"
#include "ui_changpwdialog.h"
#include "dbquery.h"

dbquery db;//新建dbquery类对象db
changPwDialog::changPwDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::changPwDialog)
{
    ui->setupUi(this);
    ui->rpErrTip->hide();
    ui->idErrTip->hide();
    connect(ui->idLineEdit,SIGNAL(editingFinished()),this,SLOT(queryname()));
    connect(ui->SubmitBtn,SIGNAL(clicked()),this,SLOT(changepw()));

}
/* 窗口构造函数
 * 窗口构造时，窗口的rpErrTip和idErrTip调用hide函数隐藏
 * 手动连接SIGNAL和SLOT
 */

void changPwDialog::queryname(){
    if(ui->idLineEdit->text().isEmpty()) {
        ui->idErrTip->show();
    }
    else{
        ui->idErrTip->hide();
        QString name = db.queryName(ui->idLineEdit->text());
        ui->nameText->setText(name.trimmed());
        QString pw = db.adminQueryPw(ui->idLineEdit->text());
        ui->oldPwText->setText(pw.trimmed());
    }
}
/* queryName函数
 * 当ui中idLineEdit控件中的文字为空时，执行函数体
 * 否则使用QString类对象name记录对象db中queryName函数查询idLineEdit控件中的文字为参数的名字
 * 并将nameText控件setText为name
 * 使用QString类对象pw记录查询到的对应id的旧密码，
 * 并将oldPwText控件setText为pw
 */

void changPwDialog::changepw(){
    if(ui->newPwLineEdit->text().operator ==(ui->rpNewPwLineEdit->text())){
        db.modPw(ui->idLineEdit->text(),ui->newPwLineEdit->text());
    }
    else ui->rpErrTip->show();
}
/* 如果用户输入的新密码和查询到的旧密码相符合
 * 调用db对象的modPw函数，输入id和newPw参数修改密码
 * 否则将rpErrTip控件显示出来
 */

changPwDialog::~changPwDialog()
{
    delete ui;
}

void changPwDialog::on_AbortBtn_clicked()//当取消按钮按下动作
{
    this->close();//通知本窗体关闭
}
