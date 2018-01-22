#-------------------------------------------------
#
# Project created by QtCreator 2018-01-16T15:16:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = wdgttest
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mywidget.cpp

HEADERS  += mainwindow.h \
    mywidget.h

FORMS    += mainwindow.ui \
    form.ui

QMAKE_CXXFLAGS += -std=c++11
