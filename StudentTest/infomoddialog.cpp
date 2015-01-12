#include "infomoddialog.h"
#include "ui_infomoddialog.h"
#include <QtSql>
#include <QMessageBox>

infoModDialog::infoModDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::infoModDialog)
{
    ui->setupUi(this);
    tablemodel = new QSqlRelationalTableModel(this);
    tablemodel->setTable("userInfo");
    tablemodel->select();

    mapper = new QDataWidgetMapper(this);
    mapper->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);
    mapper->setModel(tablemodel);
    mapper->addMapping(ui->idLineEdit,0);
    mapper->addMapping(ui->nameText,1);
    mapper->addMapping(ui->sexLineEdit,2);
    mapper->addMapping(ui->ageLineEdit,3);
    mapper->addMapping(ui->telLineEdit,6);
    mapper->addMapping(ui->addTextEdit,7);
}

infoModDialog::~infoModDialog()
{
    delete ui;
}

void infoModDialog::on_queryBtn_clicked()
{
    if(ui->idLineEdit->text().operator !=(QString("-1")) ){
        tablemodel->setFilter(QString("id='%1'").arg(ui->idLineEdit->text()));
        tablemodel->select();
        mapper->setCurrentIndex(0);
    }
    else{
        mapper->toFirst();
    }
}

void infoModDialog::on_submitBtn_clicked()
{
    if(mapper->submit()){
        QMessageBox::information(this,QString::fromUtf8("提示"),QString::fromUtf8("修改成功！"));
    }
    else{
        QMessageBox::warning(this,QString::fromUtf8("提示"),QString::fromUtf8("修改失败！\n请检查数据是否符合要求！"));
    }
}

void infoModDialog::on_closeBtn_clicked()
{
    this->close();
}
