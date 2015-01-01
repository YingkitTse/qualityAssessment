#ifndef SYSSETDIALOG_H
#define SYSSETDIALOG_H

#include <QtGui/QDialog>
#include <QSqlRelationalTableModel>

namespace Ui {
class sysSetDialog;
}

class sysSetDialog : public QDialog
{
    Q_OBJECT

public:
    explicit sysSetDialog(QWidget *parent = 0);
    ~sysSetDialog();
    void initTable();

private slots:
    void on_closeBtn_clicked();
    void on_refreshBtn_clicked();
    void on_submitBtn_clicked();
    void on_revertBtn_clicked();
    void on_queryBtn_clicked();
    void on_upSortBtn_clicked();
    void on_downSortBtn_clicked();
    void on_delBtn_clicked();
    void on_addBtn_clicked();

private:
    Ui::sysSetDialog *ui;
    QSqlRelationalTableModel *model;
};

#endif // SYSSETDIALOG_H
