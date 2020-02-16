QT += core
QT -= gui

CONFIG += c++11

TARGET = ArvoreAVL
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

HEADERS += \
    Node.h \
    TreeAVL.h \
    Rotation.h
