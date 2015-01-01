#ifndef MODASSESDIALOG_H
#define MODASSESDIALOG_H

#include <QtGui/QDialog>
#include <QSqlRelationalTableModel>
#include "dbquery.h"

namespace Ui {
class modAssesDialog;
}

class modAssesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit modAssesDialog(QWidget *parent = 0);
    ~modAssesDialog();
    void initTableView();

private slots:
    void on_closeBtn_clicked();
    void on_submitBtn_clicked();
    void on_revertBtn_clicked();
    void on_queryBtn_clicked();
    void on_queryAllBtn_clicked();
    void on_delBtn_clicked();
    void on_addBtn_clicked();

private:
    Ui::modAssesDialog *ui;
    QSqlRelationalTableModel *model;
    dbquery db;
};

#endif // MODASSESDIALOG_H
