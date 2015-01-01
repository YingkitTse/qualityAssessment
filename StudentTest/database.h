#ifndef DATABASE_H
#define DATABASE_H
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtCore>
#include <QMessageBox>
class dbase{
private:
    QSqlDatabase db;
public:
    bool OpenDatabase(){
        db = QSqlDatabase::addDatabase("QODBC");
        db.setDatabaseName( "Driver={sql server};server=localhost;database=StuTest;uid=sa;pwd=password;" );
        if (!db.open()){
            QMessageBox::critical(0,QString::fromUtf8("数据库致命错误"),
                                  db.lastError().databaseText(),
                                  QMessageBox::Cancel);
            return false;
        }
        return true;
    }
    void CloseDatabase(){
        db.close();
    }
};
#endif // DATABASE_H
