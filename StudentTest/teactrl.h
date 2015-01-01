#ifndef TEACTRL_H
#define TEACTRL_H

#include <QtGui/QMainWindow>

namespace Ui {
class teaCtrl;
}

class teaCtrl : public QMainWindow
{
    Q_OBJECT

public:
    explicit teaCtrl(QWidget *parent = 0);
    void Authorize(QString id, QString name, QString auth);
    ~teaCtrl();

private slots:
    void on_testBtn_clicked();
    void on_infoBtn_clicked();
    void on_pwBtn_clicked();
    void on_exitBtn_clicked();
    void logout();
    void about();
private:
    Ui::teaCtrl *ui;
    //QWidget *parent;
};

#endif // TEACTRL_H
