#ifndef QUERYASSESSDIALOG_H
#define QUERYASSESSDIALOG_H

#include <QDialog>

namespace Ui {
class queryAssessDialog;
}

class queryAssessDialog : public QDialog {
    Q_OBJECT

public:
    queryAssessDialog(QWidget *parent = 0);
    void Authorize(QString id, QString name);
    ~queryAssessDialog();

private slots:
    void on_closeBtn_clicked();

private:
    Ui::queryAssessDialog *ui;
};

#endif // QUERYASSESSDIALOG_H
