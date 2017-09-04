#-------------------------------------------------
#
# Project created by QtCreator 2017-09-03T13:40:43
#
#-------------------------------------------------


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = monitor-final
TEMPLATE = app

QT       += core gui printsupport


SOURCES += main.cpp\
        mainwindow.cpp \
    qcustomplot.cpp

HEADERS  += mainwindow.h \
    qcustomplot.h

FORMS    += mainwindow.ui

CONFIG += c++11
