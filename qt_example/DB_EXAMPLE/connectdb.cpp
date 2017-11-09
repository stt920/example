#include<QDebug>
#include<QSqlDatabase>
#include<QSqlQuery>
void OpenDatabase()
{
    QSqlDatabase db=QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName(QString("DRIVER={SQL SERVER};"
                               "SERVER=P-V-4;" //服务器名称
                               "DATABASE=qt_example;"//数据库名
                               "UID=sa;"           //登录名
                               "PWD=666666;"        //密码
                               )
                       .arg("172.0.0.1")
                       .arg("name")
                       .arg("username")
                       .arg("password")
                       );
    if (!db.open())
    {
        qDebug()<<"connect sql server failed!";

    }
    else
    {
        qDebug()<<"connect sql server successfully!";
    }
  //  primary key
    QSqlQuery query;
        query.exec("create table student (id int primary key , "
                   "name varchar(20))");
        query.exec("insert into student values(0, 'first')");
        query.exec("insert into student values(1, 'second')");
        query.exec("insert into student values(2, 'third')");
        query.exec("insert into student values(3, 'fourth')");
        query.exec("insert into student values(4, 'fifth')");
        //return true;
}
