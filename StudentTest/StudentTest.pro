#-------------------------------------------------
#
# Project created by QtCreator 2014-12-08T08:17:47
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = StudentTest
TEMPLATE = app


SOURCES += main.cpp\
        logindialog.cpp \
    adminctrl.cpp \
    usrctrl.cpp \
    queryAssessDialog.cpp \
    modpwdialog.cpp \
    teactrl.cpp \
    infoquerydialog.cpp \
    changpwdialog.cpp \
    infomoddialog.cpp \
    modassesdialog.cpp \
    syssetdialog.cpp

HEADERS  += logindialog.h \
    database.h \
    adminctrl.h \
    usrctrl.h \
    dbquery.h \
    queryAssessDialog.h \
    modpwdialog.h \
    teactrl.h \
    infoquerydialog.h \
    changpwdialog.h \
    infomoddialog.h \
    modassesdialog.h \
    syssetdialog.h \
    clock.h

FORMS    += logindialog.ui \
    adminctrl.ui \
    usrctrl.ui \
    queryAssessDialog.ui \
    modpwdialog.ui \
    teactrl.ui \
    infoquerydialog.ui \
    changpwdialog.ui \
    infomoddialog.ui \
    modassesdialog.ui \
    syssetdialog.ui

RESOURCES += \
    StudentTest.qrc

OTHER_FILES += \
    myicon.rc

RC_FILE = myicon.rc
