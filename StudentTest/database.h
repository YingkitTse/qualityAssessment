//database.h
//数据库连接模块
#ifndef DATABASE_H
#define DATABASE_H
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtCore>
#include <QMessageBox>
class dbase{
private:
    QSqlDatabase db;    //私有成员：QSqlDatabase类，db对象
public:
    bool OpenDatabase(){        //布尔类型函数：打开数据库
        db = QSqlDatabase::addDatabase("QODBC");                //使用QODBC驱动程序
        db.setDatabaseName( "Driver={sql server};"              //设定连接数据库参数，使用SQL Server驱动
                            "server=localhost;"                 //服务器地址
                            "database=somedb;"                 //数据库名
                            "uid=sa;"                           //登录名
                            "pwd=neverevertellyou;" );          //登录密码
        if (!db.open()){    //使用open()函数打开数据库连接，如连接失败则运行程序体
            QMessageBox::critical(0,QString::fromUtf8("数据库致命错误"),
                                  db.lastError().databaseText(),
                                  QMessageBox::Cancel);         //使用QMessageBox类弹出类型为critical（致命）的对话框，标题为”数据库致命错误“，内容为驱动返回错误信息，提供取消按钮
            return false;                                       //函数返回false值
        }
        return true;
    }
    void CloseDatabase(){ //无返回类型函数：关闭数据库连接
        db.close();         //使用QSqlDatabase类的close()函数来关闭数据库连接。
    }
};
#endif // DATABASE_H
