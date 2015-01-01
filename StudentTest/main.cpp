#include "logindialog.h"
#include "database.h"
#include <QApplication>
#include <QSplashScreen>
#include <QIcon>
#include <QMessageBox>
#include "clock.h"

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    clock cp;
    a.setWindowIcon(QIcon(":/new/icons/images/7.png"));
    QSplashScreen *splash = new QSplashScreen;
    splash->setPixmap(QPixmap(":/new/pics/images/splash.png"));
    splash->show();

    Qt::Alignment bottomRight = Qt::AlignRight | Qt::AlignBottom;
    splash->showMessage(QString::fromUtf8("Establishing connections..."),bottomRight,Qt::red);
    cp.sleep(1);
    dbase db;
    if(!db.OpenDatabase()){
        QMessageBox::critical(0,QString::fromUtf8("致命错误"),QString::fromUtf8("无法与数据库服务器建立连接！\n请检查网络连接并重试！\n程序现将关闭！"));
        return 1;
    }

    splash->showMessage(QString::fromUtf8("Loading modules..."),bottomRight,Qt::blue);
    LoginDialog w;
    cp.sleep(1);
    splash->showMessage(QString::fromUtf8("Setting up windows..."),bottomRight,Qt::yellow);
    cp.sleep(1);
    splash->showMessage(QString::fromUtf8("Initializing Login Dialog..."),bottomRight,Qt::black);
    w.show();
    splash->finish(&w);
    delete splash;

    return a.exec();
}
