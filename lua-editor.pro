#-------------------------------------------------
#
# Project created by QtCreator 2017-11-16T14:16:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = lua-editor
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    tabulation.cpp

HEADERS  += mainwindow.h \
    tabulation.h

FORMS    += mainwindow.ui

DISTFILES += \
    updates.txt \
    dani_part.txt
