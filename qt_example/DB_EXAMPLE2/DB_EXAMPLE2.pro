#-------------------------------------------------
#
# Project created by QtCreator 2017-11-07T10:25:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DB_EXAMPLE2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    connectdb.cpp \
    mysqlquerymodel.cpp

HEADERS  += mainwindow.h \
    connectdb.h \
    mysqlquerymodel.h

FORMS    += mainwindow.ui
QT += sql
