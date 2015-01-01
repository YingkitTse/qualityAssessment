#ifndef USRCTRL_H
#define USRCTRL_H

#include <QMainWindow>

namespace Ui {
class usrCtrl;
}

class usrCtrl : public QMainWindow {
    Q_OBJECT

public:
    usrCtrl(QWidget *parent = 0);
    void Authorize(QString id, QString name, QString auth);
    ~usrCtrl();
private slots:
    void on_testBtn_clicked();
    void on_exitBtn_clicked();
    void on_modpwBtn_clicked();
    void on_infoBtn_clicked();
    void logout();
    void about();
private:
    Ui::usrCtrl *ui;
    //QWidget *parent;
};

#endif // USRCTRL_H
