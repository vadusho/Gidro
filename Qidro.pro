QT += core
QT += xml
QT -= gui

TARGET = Qidro
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    helpers_fun.cpp \
    workxml.cpp \
    calcmodules.cpp \
    createelements.cpp

HEADERS += \
    workxml.h \
    calcmodules.h \
    createelements.h

