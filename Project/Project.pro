#-------------------------------------------------
#
# Project created by QtCreator 2013-02-23T20:03:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Project
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    processdialog.cpp \
    analizator.cpp

HEADERS  += mainwindow.h \
    processdialog.h \
    analizator.h

FORMS    += mainwindow.ui \
    chooseProcess.ui
