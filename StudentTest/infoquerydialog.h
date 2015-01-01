#ifndef INFOQUERYDIALOG_H
#define INFOQUERYDIALOG_H

#include <QtGui/QDialog>

namespace Ui {
class infoQueryDialog;
}

class infoQueryDialog : public QDialog
{
    Q_OBJECT

public:
    explicit infoQueryDialog(QWidget *parent = 0);
    ~infoQueryDialog();
    void Authorize(QString id, QString name);

private slots:
    void on_pushButton_clicked();

private:
    Ui::infoQueryDialog *ui;
};

#endif // INFOQUERYDIALOG_H
