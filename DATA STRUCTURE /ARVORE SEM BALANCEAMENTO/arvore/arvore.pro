QT += core
QT -= gui

CONFIG += c++11

TARGET = arvore
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

HEADERS += \
    Tree.h \
    Node.h
