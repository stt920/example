#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connectdb.h"
#include <QSqlQueryModel>
#include <QTableView>
#include <QSqlRecord>
#include<QModelIndex>
#include<QDebug>
#include<QSqlQuery>
#include<mysqlquerymodel.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    OpenDatabase();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
       QSqlQuery query;
        query.exec("create table student (id int primary key , "
                   "name varchar(20))");
        query.exec("insert into student values(0, 'first')");
        query.exec("insert into student values(1, 'second')");
        query.exec("insert into student values(2, 'third')");
        query.exec("insert into student values(3, 'fourth')");
        query.exec("insert into student values(4, 'fifth')");


       QSqlQueryModel *model = new QSqlQueryModel(this);
       model->setQuery("select * from student");
       model->setHeaderData(0, Qt::Horizontal, tr("id"));
       model->setHeaderData(1, Qt::Horizontal, tr("name"));


       query = model->query();
          query.exec("insert into student values (10,'yafei10')");




       QTableView *view = new QTableView;
       view->setModel(model);
       view->show();


       int column = model->columnCount(); //获得列数
       int row = model->rowCount();    // 获得行数
       QSqlRecord record = model->record(1); //获得一条记录
       QModelIndex index = model->index(1, 1);   //获得一条记录的一个字段的索引
       qDebug() << "column num is:" << column << endl
                << "row num is:" << row << endl
                <<"the second record is:" << record << endl
               << "the data of index(1,1) is:"<< index.data();
}

void MainWindow::on_pushButton_2_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel(this);
       model->setQuery("select* from student");
      model->setHeaderData(0, Qt::Horizontal, tr("id"));
      model->setHeaderData(1, Qt::Horizontal, tr("name"));
      QTableView *view = new QTableView;
      view->setModel(model);
      view->show();

   //创建自己模型的对象
      MySqlQueryModel *myModel = new MySqlQueryModel(this);
      myModel->setQuery("select * from student");
      myModel->setHeaderData(0, Qt::Horizontal, tr("id"));
      myModel->setHeaderData(1, Qt::Horizontal, tr("name"));
      QTableView *view1 = new QTableView;
      view1->setWindowTitle("mySqlQueryModel"); //修改窗口标题
      view1->setModel(myModel);
      view1->show();
}
