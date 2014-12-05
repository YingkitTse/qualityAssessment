#include "querydialog.h"
#include "ui_querydialog.h"

queryDialog::queryDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::queryDialog)
{
    ui->setupUi(this);
}

queryDialog::~queryDialog()
{
    delete ui;
}
