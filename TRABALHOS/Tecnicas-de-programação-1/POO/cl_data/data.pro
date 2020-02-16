QT += core
QT -= gui

CONFIG += c++11

TARGET = cl_data
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    cl_data.cpp \
    interface.cpp

HEADERS += \
    cl_data.h \
    interface.h
