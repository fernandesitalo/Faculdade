QT += core
QT -= gui

CONFIG += c++11

TARGET = My_stack
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    Stack.cpp \
    Node.cpp \
    Carta.cpp \
    Queue.cpp

HEADERS += \
    Stack.h \
    Node.h \
    Carta.h \
    Queue.h
