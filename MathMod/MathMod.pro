#-------------------------------------------------
#
# Project created by QtCreator 2013-04-24T09:32:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MathMod
TEMPLATE = app

CONFIG(debug, release|debug){
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
    Matmod/System.cpp \
    Matmod/Point.cpp \
    Matmod/Area.cpp \
    Widgets/rangewidget.cpp \
    Widgets/qsliderjump.cpp \
    Widgets/pointsetterwidget.cpp \
    Widgets/parametrswidget.cpp \
    Widgets/observationpointwidget.cpp \
    Widgets/areawidget.cpp \
    Matmod/passport.cpp \
    Matmod/wolframobject.cpp \
    dialogchooseexistprocess.cpp \
    3rdparty/QCustomPlot/include/qcustomplot.cpp \
    Widgets/plotdrawing.cpp

HEADERS  += mainwindow.h \
    Matmod/System.h \
    Matmod/Range.h \
    Matmod/Point.h \
    Matmod/mathmod.h \
    Matmod/Area.h \
    Widgets/rangewidget.h \
    Widgets/qsliderjump.h \
    Widgets/pointsetterwidget.h \
    Widgets/parametrswidget.h \
    Widgets/observationpointwidget.h \
    Widgets/areawidget.h \
    Matmod/passport.h \
    Matmod/wolframobject.h \
    dialogchooseexistprocess.h \
    3rdparty/QCustomPlot/include/qcustomplot.h \
    Widgets/plotdrawing.h

#LIBS += C:/Qt/Qt5.0.1/Tools/MinGW/i686-w64-mingw32/lib/ml32i3m.lib
LIBS += E:/QT/5.0.1/Tools/MinGW/i686-w64-mingw32/lib/ml32i3m.lib

FORMS    += mainwindow.ui \
    dialogchooseexistprocess.ui
