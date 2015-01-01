#ifndef INFOMODDIALOG_H
#define INFOMODDIALOG_H

#include <QtGui/QDialog>
#include <QSqlRelationalTableModel>
#include <QDataWidgetMapper>

namespace Ui {
class infoModDialog;
}

class infoModDialog : public QDialog
{
    Q_OBJECT

public:
    explicit infoModDialog(QWidget *parent = 0);
    ~infoModDialog();

private slots:
    void on_queryBtn_clicked();
    void on_submitBtn_clicked();
    void on_closeBtn_clicked();

private:
    Ui::infoModDialog *ui;
    QSqlRelationalTableModel *tablemodel;
    QDataWidgetMapper *mapper;
};

#endif // INFOMODDIALOG_H
