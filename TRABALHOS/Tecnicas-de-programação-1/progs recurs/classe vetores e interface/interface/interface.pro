QT += core
QT -= gui

CONFIG += c++11

TARGET = interface
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    interface.cpp

HEADERS += \
    interface.h
