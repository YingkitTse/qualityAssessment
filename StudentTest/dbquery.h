//dbquery.h
//数据库查询语句模块
#ifndef DBQUERY_H
#define DBQUERY_H
#include <QtSql/QtSql>
#include <QMessageBox>
#include <QString>
class dbquery{  //新建类，名为dbquery
public:
    bool Authenticated(QString id, QString pw, QString auth){
        QSqlQuery query;
        query.prepare("SELECT pw FROM userInfo WHERE id=:xid and auth=:xauth");
        query.bindValue(":xid",id);
        query.bindValue(":xauth",auth);
        query.exec();
        query.next();
        QString xpw = query.value(0).toString().trimmed();
        bool check = xpw.operator==(pw);
        return check;
    }
    /* 布尔类型函数：Authenticated
     * 作用：验证用户输入的用户名密码是否正确
     * 输入参数：用户名id，密码pw，用户权限auth
     * 新建QSqlQuery类对象query
     * 使用prepare函数准备一个带参数的SQL语句，参数为xid和xauth，分别对应id和auth
     * 使用exec函数执行SQL语句
     * 执行之后使用next函数使程序指向查询到的第一条记录
     * 使用QString类新建对象xpw读取记录的密码项，并使用trimmed函数去掉前后的空格
     * 使用QString类的operator==函数跟用户输入的密码pw进行对比
     * 返回对比值check
     */

    QString queryName(QString id){
      QSqlQuery query;
      query.prepare("SELECT name FROM userInfo WHERE id=:xid");
      query.bindValue(":xid",id);
      query.exec();
      query.next();
      QString str = query.value(0).toString();
      return str;
    }
    /* QString类函数：queryName
     * 作用：查询对应id的名字
     * 输入参数：用户名id
     * 新建QSqlQuery类对象query
     * 使用prepare函数准备一个带参数的SQL语句，参数为xid对应id
     * 使用exec函数执行SQL语句
     * 使用next函数让程序指向第一条记录
     * 新建QString类对象str读取记录的姓名项并返回str的值
     */

    QString adminQueryPw(QString id){
        QSqlQuery query;
        query.prepare("SELECT pw FROM userInfo WHERE id=:xid");
        query.bindValue(":xid",id);
        query.exec();
        query.next();
        QString str = query.value(0).toString();
        return str;
    }
    /* QString类函数adminQueryPw
     * 作用：管理员使用的查询密码函数
     * 输入参数：用户名id
     */

    bool modPw(QString id, QString newpw){
        QSqlQuery query;
        query.prepare("update userInfo set pw=:xnewpw where id=:xid");
        query.bindValue(":xnewpw",newpw);
        query.bindValue(":xid",id);
        query.exec();
        return true;
    }
    /* 布尔类型函数：modPw
     * 作用：修改密码
     * 使用query对象提交SQL语句update修改指定id的pw项
     * 输入参数：用户名id，新密码newpw
     */
};

#endif // DBQUERY_H
