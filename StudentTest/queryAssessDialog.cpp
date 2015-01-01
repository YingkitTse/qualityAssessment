#include "queryAssessDialog.h"
#include "ui_queryAssessDialog.h"
#include <QtSql>
#include <QApplication>

static QString xname;
static QString xid;

queryAssessDialog::queryAssessDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::queryAssessDialog)
{
    ui->setupUi(this);
}

void queryAssessDialog::Authorize(QString id, QString name){
    xname = name;
    xid = id;
    ui->nameLabel->setText(xname);
    ui->idLabel->setText(xid);
    QSqlTableModel *model = new QSqlTableModel(this);
    model->setTable("testInfo");
    model->setHeaderData(0,Qt::Horizontal,QString::fromUtf8("学号"));
    model->setHeaderData(1,Qt::Horizontal,QString::fromUtf8("项目"));
    model->setHeaderData(2,Qt::Horizontal,QString::fromUtf8("类别"));
    model->setHeaderData(3,Qt::Horizontal,QString::fromUtf8("分数"));
    model->setFilter(tr("id='%1'").arg(xid));
    model->select();
    ui->tableView->setModel(model);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

queryAssessDialog::~queryAssessDialog()
{
    delete ui;
}

void queryAssessDialog::on_closeBtn_clicked()
{
    accept();
}
