QT += core
QT -= gui

CONFIG += c++11

TARGET = Trabalho_Stack_Queue
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    Ficha.cpp


HEADERS += \
    Stack.h \
    Node.h \
    Queue.h \
    Ficha.h
