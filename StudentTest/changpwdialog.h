#ifndef CHANGPWDIALOG_H
#define CHANGPWDIALOG_H

#include <QtGui/QDialog>

namespace Ui {
class changPwDialog;
}

class changPwDialog : public QDialog
{
    Q_OBJECT

public:
    explicit changPwDialog(QWidget *parent = 0);
    ~changPwDialog();
private slots:                  //槽动作
    void queryname();
    void changepw();
    void on_AbortBtn_clicked();

private:
    Ui::changPwDialog *ui;
};

#endif // CHANGPWDIALOG_H
