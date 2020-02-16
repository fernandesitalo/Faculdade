#-------------------------------------------------
#
# Project created by QtCreator 2016-11-30T13:34:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Teste_Interface
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    pessoa.cpp \
    criarpessoa.cpp

HEADERS  += mainwindow.h \
    pessoa.h \
    criarpessoa.h

FORMS    += mainwindow.ui \
    criarpessoa.ui
