#-------------------------------------------------
#
# Project created by QtCreator 2015-11-07T14:58:01
#
#-------------------------------------------------

QT       += core gui webkitwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = zo
TEMPLATE = app


SOURCES += main.cpp\
        mw.cpp \
    flashcart.cpp \
    download.cpp

HEADERS  += mw.h \
    flashcart.h \
    download.h

FORMS    += mw.ui
CONFIG += c++11
