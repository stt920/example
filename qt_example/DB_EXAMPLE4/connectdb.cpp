#include "connectdb.h"
#include<QSqlDatabase>
#include<QDebug>
#include<QSqlQuery>
void connectdb()
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

//    QSqlQuery query;
//        query.exec("create table student1 (id int primary key , "
//                   "name varchar(20))");
//        query.exec("insert into student1 values(0, 'first')");
//        query.exec("insert into student1 values(1, 'second')");
//        query.exec("insert into student1 values(2, 'third')");
//        query.exec("insert into student1 values(3, 'fourth')");
//        query.exec("insert into student1 values(4, 'fifth')");
       QSqlQuery query;
       query.exec("create table student1 (id int primary key, name varchar(20),course int,teacher varchar(20))");
       query.exec("insert into student1 values(1,'yafei0',1,NULL)");
       query.exec("insert into student1 values(2,'yafei1',1,NULL)");
       query.exec("insert into student1 values(3,'yafei2',2,NULL)");

       query.exec("create table course (id int primary key, name varchar(20), teacher varchar(20))");
       query.exec("insert into course values(1,'Math','yafeilinux1')");
       query.exec("insert into course values(2,'English','yafeilinux2')");
       query.exec("insert into course values(3,'Computer','yafeilinux3')");

       qDebug()<<"创建表成功";

}
