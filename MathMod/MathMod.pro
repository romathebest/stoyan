#-------------------------------------------------
#
# Project created by QtCreator 2013-04-24T09:32:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MathMod
TEMPLATE = app


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
    Matmod/wolframobject.cpp

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
    Matmod/wolframobject.h

LIBS += C:/Qt/Qt5.0.1/Tools/MinGW/i686-w64-mingw32/lib/ml32i3m.lib

FORMS    += mainwindow.ui
