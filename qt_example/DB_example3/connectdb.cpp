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

}
