#include "infoquerydialog.h"
#include "ui_infoquerydialog.h"
#include <QtSql>
#include <QTableView>

static QString xid;
static QString xname;

infoQueryDialog::infoQueryDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::infoQueryDialog)
{
    ui->setupUi(this);
}

void infoQueryDialog::Authorize(QString id, QString name){
    xid = id;
    xname = name;
    QSqlQuery query;
    query.prepare("SELECT name,sex,age,tel,address FROM userInfo WHERE id=:xid");
    query.bindValue(":xid",xid);
    query.exec();
    query.next();
    ui->idText->setText(xid);
    ui->authText->setText(QString::fromUtf8("学生"));
    ui->sexText->setText(query.value(1).toString());
    ui->ageText->setText(query.value(2).toString());
    ui->telText->setText(query.value(3).toString());
    ui->addText->setText(query.value(4).toString());
    ui->nameText->setText(query.value(0).toString());
}

infoQueryDialog::~infoQueryDialog()
{
    delete ui;
}

void infoQueryDialog::on_pushButton_clicked()
{
    this->close();
}
