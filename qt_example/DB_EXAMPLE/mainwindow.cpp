#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connectdb.h"
#include <QSqlQuery>
#include <QDebug>
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
        query.exec("select * from student");
        while(query.next())
        {
            qDebug() << query.value(0).toInt()
                           << query.value(1).toString();
        }
}

void MainWindow::on_pushButton_2_clicked()
{
    QSqlQuery query;
    query.exec("select * from student");
         query.seek(2);
         qDebug() << query.value(0).toInt()
                        << query.value(1).toString();

}

void MainWindow::on_pushButton_3_clicked()
{
    QSqlQuery query;


        int id = ui->spinBox->value();
        query.exec(QString("select name from student where id=%1")
                   .arg(id));
        query.next();
        QString name = query.value(0).toString();
        qDebug() << name;
}

void MainWindow::on_pushButton_4_clicked()
{


    QSqlQuery query;
        query.prepare("insert into student (id, name) "
                      "values (:id, :name)");
        query.bindValue(0, 5);
        query.bindValue(1, "sixth");
        query.exec();
        query.exec("select * from student");
        query.last();
        int id = query.value(0).toInt();
        QString name = query.value(1).toString();
        qDebug() << id << name;
}

void MainWindow::on_pushButton_5_clicked()
{
    QSqlQuery query;
        query.prepare("select name from student where id = ?");
        int id = ui->spinBox->value();
        query.addBindValue(id);
        query.exec();
        query.next();
        qDebug() << query.value(0).toString();
}
