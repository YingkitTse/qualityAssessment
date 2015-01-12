#include "syssetdialog.h"
#include "ui_syssetdialog.h"
#include <QMessageBox>
#include <QSqlError>
#include <QSqlRelationalDelegate>

sysSetDialog::sysSetDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sysSetDialog)
{
    ui->setupUi(this);
    model = new QSqlRelationalTableModel(this);
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    this->initTable();
    ui->tableView->setModel(model);
    ui->tableView->setItemDelegate(new QSqlRelationalDelegate(ui->tableView));
}

sysSetDialog::~sysSetDialog()
{
    delete ui;
}

void sysSetDialog::on_closeBtn_clicked()
{
    this->close();
}

void sysSetDialog::initTable(){
    model->setTable("userInfo");
    model->setRelation(5,QSqlRelation("auth","no","name"));
    model->setHeaderData(0,Qt::Horizontal,QString::fromUtf8("学/工号"));
    model->setHeaderData(1,Qt::Horizontal,QString::fromUtf8("姓名"));
    model->setHeaderData(2,Qt::Horizontal,QString::fromUtf8("性别"));
    model->setHeaderData(3,Qt::Horizontal,QString::fromUtf8("年龄"));
    model->setHeaderData(4,Qt::Horizontal,QString::fromUtf8("密码"));
    model->setHeaderData(5,Qt::Horizontal,QString::fromUtf8("操作权限"));
    model->setHeaderData(6,Qt::Horizontal,QString::fromUtf8("电话"));
    model->setHeaderData(7,Qt::Horizontal,QString::fromUtf8("住址"));
    model->select();
}

void sysSetDialog::on_refreshBtn_clicked()
{
    this->initTable();
    model->select();
}

void sysSetDialog::on_submitBtn_clicked()
{
    model->database().transaction();
    if(model->submitAll()){
        model->database().commit();
        QMessageBox::information(this,QString::fromUtf8("提示"),QString::fromUtf8("数据库操作提交成功！"));
        this->initTable();
        model->select();
    }
    else{
        model->database().rollback();
        QMessageBox::warning(this,QString::fromUtf8("提示"),QString::fromUtf8("数据库错误！\n提示信息：%1").arg(model->lastError().text()));
    }
}

void sysSetDialog::on_revertBtn_clicked()
{
    model->revertAll();
}

void sysSetDialog::on_queryBtn_clicked()
{
    QString id = ui->idLineEdit->text();
    model->setFilter(QString("id='%1'").arg(id));
    //this->initTable();
    model->select();
}

void sysSetDialog::on_upSortBtn_clicked()
{
    model->setSort(0,Qt::AscendingOrder);
    this->initTable();
    model->select();
}

void sysSetDialog::on_downSortBtn_clicked()
{
    model->setSort(0,Qt::DescendingOrder);
    this->initTable();
    model->select();
}

void sysSetDialog::on_delBtn_clicked()
{
    int curRow = ui->tableView->currentIndex().row();
    model->removeRow(curRow);
    int ok = QMessageBox::warning(this,QString::fromUtf8("确认操作"),QString::fromUtf8("你确定要删除此行数据吗？\n一旦确认此操作将不能恢复！"),QMessageBox::Yes,QMessageBox::No);
    if(ok == QMessageBox::No){
        model->revertAll();
    }
    else{
        model->submitAll();
        QMessageBox::information(this,QString::fromUtf8("提示"),QString::fromUtf8("数据库删除操作成功！"));
        this->initTable();
        model->select();
    }
}

void sysSetDialog::on_addBtn_clicked()
{
    int rowNum = model->rowCount();
    model->insertRow(rowNum);
    model->setData(model->index(rowNum,0),QString::fromUtf8("学/工号"));
    model->setData(model->index(rowNum,1),QString::fromUtf8("姓名"));
    model->setData(model->index(rowNum,2),QString::fromUtf8("性别"));
    model->setData(model->index(rowNum,3),QString::fromUtf8("年龄"));
    model->setData(model->index(rowNum,4),QString::fromUtf8("密码"));
    //model->setData(model->index(rowNum,5),QString::fromUtf8("操作权限"));
    model->setData(model->index(rowNum,6),QString::fromUtf8("电话"));
    model->setData(model->index(rowNum,7),QString::fromUtf8("住址"));
}
