QT += core
QT -= gui

CONFIG += c++11

TARGET = ListaD
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    noded.cpp \
    Aluno.cpp \
    ListaDE.cpp

HEADERS += \
    noded.h \
    Aluno.h \
    ListaDE.h
