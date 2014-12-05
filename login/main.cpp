#include "mainwindow.h"
#include "logindialog.h"
#include "querydialog.h"
#include <QApplication>

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlDriver>
#include <QtSql/QtSql>
#include <QMessageBox>

bool OpenDatabase(){
    QSqlDatabase db=QSqlDatabase::addDatabase("QODBC");
    QString dsn = QString("Driver={sql server};server=kit-laptop;database=StuTest;uid=sa;pwd=superadmin123059;");
    db.setDatabaseName( dsn );
    if (!db.open()){
        QMessageBox::critical(0,qApp->tr("Can not open database!!"),
                              db.lastError().databaseText(),
                              QMessageBox::Cancel);
        return false;
    }
    return true;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    if(!OpenDatabase()){
        return 1;
    }
    MainWindow w;
    LoginDialog logindlg;
    if(login.exec() == QDialog::Accepted){
        w.show();
        return a.exec();
    }
    else return 0;
}
