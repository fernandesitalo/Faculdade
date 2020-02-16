#-------------------------------------------------
#
# Project created by QtCreator 2016-12-08T19:41:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AED_final
TEMPLATE = app


SOURCES += main.cpp\
        TelaPrincipal.cpp \
    AtualizarCliente.cpp \
    AtualizarEquipamento.cpp \
    CadrastroCliente.cpp \
    CadrastroEquipamento.cpp \
    Cliente.cpp \
    Equipamentos.cpp \
    Arquivos.cpp \
    IndiceCl.cpp \
    INDCL.cpp \
    INDEQ.cpp \
    IndiceEq.cpp \
    AlugarEquipamento.cpp \
    INDALUGA.cpp \
    ConsultaAlugueis.cpp \
    IndiceAl.cpp

HEADERS  += TelaPrincipal.h \
    AtualizarCliente.h \
    AtualizarEquipamento.h \
    CadrastroCliente.h \
    CadrastroEquipamento.h \
    Cliente.h \
    Equipamentos.h \
    Arquivos.h \
    IndiceCl.h \
    INDCL.h \
    INDEQ.h \
    IndiceEq.h \
    AlugarEquipamento.h \
    INDALUGA.h \
    ConsultaAlugueis.h \
    IndiceAl.h

FORMS    += TelaPrincipal.ui \
    AtualizarCliente.ui \
    AtualizarEquipamento.ui \
    CadrastroCliente.ui \
    CadrastroEquipamento.ui \
    AlugarEquipamento.ui \
    ConsultaAlugueis.ui

RESOURCES += \
    imagem.qrc

DISTFILES +=
