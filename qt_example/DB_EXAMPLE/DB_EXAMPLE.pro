#-------------------------------------------------
#
# Project created by QtCreator 2017-11-06T20:00:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DB_EXAMPLE
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    connectdb.cpp

HEADERS  += mainwindow.h \
    connectdb.h

FORMS    += mainwindow.ui

QT += sql
