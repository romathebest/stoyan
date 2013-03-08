#-------------------------------------------------
#
# Project created by QtCreator 2013-02-23T20:03:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Project
TEMPLATE = app


CONFIG(debug, release|debug) {
  win32:QCPLIB = qcustomplotd1
  else: QCPLIB = qcustomplotd
} else {
  win32:QCPLIB = qcustomplot1
  else: QCPLIB = qcustomplot
}
LIBS += -L"$$_PRO_FILE_PWD_/3rdparty/QCustomPlot/lib/" -l$$QCPLIB

INCLUDEPATH += $$_PRO_FILE_PWD_/3rdparty/QCustomPlot/include

SOURCES += main.cpp\
        mainwindow.cpp \
    processdialog.cpp \
    analizator.cpp \
    system.cpp \
    area.cpp

HEADERS  += mainwindow.h \
    processdialog.h \
    analizator.h \
    system.h \
    point3.h \
    area.h

FORMS    += mainwindow.ui \
    chooseProcess.ui
