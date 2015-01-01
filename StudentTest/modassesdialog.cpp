#include "modassesdialog.h"
#include "ui_modassesdialog.h"
#include <QMessageBox>
#include <QSqlError>
/**************************************
 * 本对话框程序设计参考
 * http://bbs.qter.org/forum.php?mod=viewthread&tid=186
 **************************************/

static QString xid;
static QString xname;

modAssesDialog::modAssesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modAssesDialog)
{
    ui->setupUi(this);
    model = new QSqlRelationalTableModel(this);
    model->setTable("testInfo");
    model->setRelation(2,QSqlRelation("cata","no","name"));
    this->initTableView();
    ui->tableView->setModel(model);
    ui->tableView->setItemDelegate(new QSqlRelationalDelegate(ui->tableView));
}

modAssesDialog::~modAssesDialog()
{
    delete ui;
}
void modAssesDialog::initTableView(){
    model->setHeaderData(0,Qt::Horizontal,QString::fromUtf8("学号"));
    model->setHeaderData(1,Qt::Horizontal,QString::fromUtf8("项目"));
    model->setHeaderData(2,Qt::Horizontal,QString::fromUtf8("类别"));
    model->setHeaderData(3,Qt::Horizontal,QString::fromUtf8("分数"));
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    //model->removeColumn(0);
}

void modAssesDialog::on_closeBtn_clicked()
{
    this->close();
}

void modAssesDialog::on_submitBtn_clicked()
{
    model->database().transaction();
    if(model->submitAll()){
        model->database().commit();
        this->on_queryBtn_clicked();
    }
    else{
        model->database().rollback();
        QMessageBox::warning(0,QString::fromUtf8("DataBase Error Call"),QString::fromUtf8("数据库错误！\n提示信息：%1").arg(model->lastError().text()));
    }
}

void modAssesDialog::on_revertBtn_clicked()
{
    model->revertAll();
}

void modAssesDialog::on_queryBtn_clicked()
{
    QString id = ui->idLineEdit->text().trimmed();
    QString name = db.queryName(id);
    ui->nameText->setText(name);
    model->setFilter(QString("id='%1'").arg(id));
    model->select();
}

void modAssesDialog::on_queryAllBtn_clicked()
{
    this->initTableView();
}

void modAssesDialog::on_delBtn_clicked()
{
    int curRow = ui->tableView->currentIndex().row();
    model->removeRow(curRow);
    int ok = QMessageBox::warning(this,QString::fromUtf8("确认操作"),QString::fromUtf8("你确定删除该行数据吗？"),QMessageBox::Yes,QMessageBox::No);
    if(ok == QMessageBox::No){
        model->revertAll();
    }
    else model->submitAll();
}

void modAssesDialog::on_addBtn_clicked()
{
    int rowNum = model->rowCount();
    model->insertRow(rowNum);
    model->setData(model->index(rowNum,0),ui->idLineEdit->text());
    //model->setData(model->index(rowNum,1),QString::fromUtf8("项目名"));
    model->setData(model->index(rowNum,2),QString::fromUtf8("类别"));
    model->setData(model->index(rowNum,3),QString::fromUtf8("分数"));
}
