#-------------------------------------------------
#
# Project created by QtCreator 2016-06-14T12:49:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Versuch8
TEMPLATE = app


SOURCES += main.cpp\
        streetplanner.cpp \
    city.cpp \
    map.cpp \
    street.cpp \
    dialog.cpp \
    mapionrw.cpp \
    test.cpp \
    dijkstra.cpp \
    mapiofileinput.cpp

HEADERS  += streetplanner.h \
    city.h \
    map.h \
    abstractmap.h \
    street.h \
    dialog.h \
    mapio.h \
    mapionrw.h \
    dijkstra.h \
    mapiofileinput.h

FORMS    += streetplanner.ui \
    dialog.ui

CONFIG += c++11
