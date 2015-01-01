#ifndef DBQUERY_H
#define DBQUERY_H
#include <QtSql/QtSql>
#include <QMessageBox>
#include <QString>
class dbquery{
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

    QString queryName(QString id){
      QSqlQuery query;
      query.prepare("SELECT name FROM userInfo WHERE id=:xid");
      query.bindValue(":xid",id);
      query.exec();
      query.next();
      QString str = query.value(0).toString();
      return str;
    }

    QString adminQueryPw(QString id){
        QSqlQuery query;
        query.prepare("SELECT pw FROM userInfo WHERE id=:xid");
        query.bindValue(":xid",id);
        query.exec();
        query.next();
        QString str = query.value(0).toString();
        return str;
    }

    bool modPw(QString id, QString newpw){
        QSqlQuery query;
        query.prepare("update userInfo set pw=:xnewpw where id=:xid");
        query.bindValue(":xnewpw",newpw);
        query.bindValue(":xid",id);
        query.exec();
        return true;
    }
};

#endif // DBQUERY_H
