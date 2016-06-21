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
    dialog.cpp

HEADERS  += streetplanner.h \
    city.h \
    map.h \
    abstractmap.h \
    street.h \
    dialog.h

FORMS    += streetplanner.ui \
    dialog.ui

CONFIG += c++11
