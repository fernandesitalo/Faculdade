#include "consulta.h"
#include "ui_consulta.h"
#include "indice.h"
#include "games.h"
#include <fstream>
using namespace std;
#include <iostream>
#include "lig.h"
#include "arquivo.h"
#include <cstring>
#include <QMessageBox>


consulta::consulta(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::consulta)
{
    ui->setupUi(this);
}

consulta::~consulta()
{
    delete ui;
}

void consulta::on_procurar_clicked()
{

    try
    {
        indice procura;
        games ex;
        arquivo game;
        QMessageBox show;
        char nome[30];
        int c;

        strcpy(nome,ui->nomee->text().toStdString().c_str());
        c = procura.getposic(nome);
        if(c < 0)
              show.information(this," ","Game nao encontrado");
        else
        {
            game.ler(&ex,c);
            ex.getnome(nome);
            ui->Nomeedit->setText(nome);
            ui->Codigoedit->setText(QString::number(ex.getcod()));
            ex.getconsole(nome);
            ui->consoleedit->setText(nome);
            ui->etariaedit->setText(QString::number(ex.getetaria()));
            ex.getgenero(nome);
            ui->generoedit->setText(nome);
            ui->qtdedit->setText(QString::number(ex.getqtd()));
            ui->Valoredit->setText(QString::number(ex.getvalor()));
        }
    }

    catch(const char b)
    {
        QMessageBox::warning(this,"","Memoria insufuciente !");
    }
    catch(...)
    {
        QMessageBox::warning(this,"","erro !");
    }
}

void consulta::on_sair_clicked()
{
    this->hide();
}
