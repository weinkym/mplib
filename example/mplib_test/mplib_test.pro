#-------------------------------------------------
#
# Project created by QtCreator 2014-06-11T11:35:08
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mplib_test
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui


LIBS +=   -L../../../../../lib -lmplib
#contains(QMAKE_CC,cl){
#-LD:/workroot/lib
#}
INCLUDEPATH += ../../include
