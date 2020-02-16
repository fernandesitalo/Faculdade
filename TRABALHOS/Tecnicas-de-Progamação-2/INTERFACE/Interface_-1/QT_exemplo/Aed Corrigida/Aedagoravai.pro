#-------------------------------------------------
#
# Project created by QtCreator 2016-11-30T14:15:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Aedagoravai
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    cadastro.cpp \
    games.cpp \
    arquivo.cpp \
    indice.cpp \
    lig.cpp \
    consulta.cpp \
    estoque.cpp \
    venda.cpp

HEADERS  += mainwindow.h \
    cadastro.h \
    games.h \
    arquivo.h \
    indice.h \
    lig.h \
    consulta.h \
    estoque.h \
    venda.h

FORMS    += mainwindow.ui \
    cadastro.ui \
    consulta.ui \
    estoque.ui \
    venda.ui

RESOURCES += \
    a.qrc
