QT += core
QT -= gui

CONFIG += c++11

TARGET = vetores_classe
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    vetor.cpp \
    interface.cpp

HEADERS += \
    vetor.h \
    interface.h
