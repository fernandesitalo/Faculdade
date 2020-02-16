QT += core
QT -= gui

CONFIG += c++11

TARGET = validarCPF
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    cpf_cl.cpp

HEADERS += \
    cpf_cl.h
