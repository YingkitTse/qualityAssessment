#ifndef QUERYDIALOG_H
#define QUERYDIALOG_H

#include <QDialog>

namespace Ui {
class queryDialog;
}

class queryDialog : public QDialog
{
    Q_OBJECT

public:
    explicit queryDialog(QWidget *parent = 0);
    ~queryDialog();

private:
    Ui::queryDialog *ui;
};

#endif // QUERYDIALOG_H
