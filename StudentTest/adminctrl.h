#ifndef ADMINCTRL_H
#define ADMINCTRL_H

#include <QMainWindow>

namespace Ui {
class adminCtrl;
}

class adminCtrl : public QMainWindow {
    Q_OBJECT

public:
    adminCtrl(QWidget *parent = 0);
    void Authorize(QString id, QString name, QString auth);
    ~adminCtrl();

private slots:
    void on_exitBtn_clicked();
    void on_modpw_clicked();
    void on_testBtn_clicked();
    void on_infoBtn_clicked();
    void on_sysBtn_clicked();
    void logout();
    void about();

private:
    Ui::adminCtrl *ui;
};

#endif // ADMINCTRL_H
