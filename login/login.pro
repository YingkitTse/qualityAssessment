#-------------------------------------------------
#
# Project created by QtCreator 2014-12-03T16:22:18
#
#-------------------------------------------------

QT       += core gui
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = login
TEMPLATE = app


SOURCES += main.cpp\
    logindialog.cpp \
    mainwindow.cpp \
    querydialog.cpp

HEADERS  += mainwindow.h \
    logindialog.h \
    _Glo.h \
    querydialog.h

FORMS    += mainwindow.ui \
    logindialog.ui \
    querydialog.ui
