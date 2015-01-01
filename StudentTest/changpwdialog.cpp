#include "changpwdialog.h"
#include "ui_changpwdialog.h"
#include "dbquery.h"

dbquery db;
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
void changPwDialog::changepw(){
    if(ui->newPwLineEdit->text().operator ==(ui->rpNewPwLineEdit->text())){
        db.modPw(ui->idLineEdit->text(),ui->newPwLineEdit->text());
    }
    else ui->rpErrTip->show();
}

changPwDialog::~changPwDialog()
{
    delete ui;
}

void changPwDialog::on_AbortBtn_clicked()
{
    this->close();
}
