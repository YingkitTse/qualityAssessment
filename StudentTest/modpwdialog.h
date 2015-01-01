#ifndef MODPWDIALOG_H
#define MODPWDIALOG_H

#include <QDialog>

namespace Ui {
class modPwDialog;
}

class modPwDialog : public QDialog {
    Q_OBJECT

public:
    modPwDialog(QWidget *parent = 0);
    void Authorize(QString auth, QString id);
    ~modPwDialog();

private slots:
    void on_OkBtn_clicked();
    void on_cancelBtn_clicked();

private:
    Ui::modPwDialog *ui;
};

#endif // MODPWDIALOG_H
