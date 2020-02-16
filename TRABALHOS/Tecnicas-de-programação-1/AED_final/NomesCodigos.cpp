#include "NomesCodigos.h"
#include "ui_NomesCodigos.h"
#include "IndiceEq.h"
#include "Arquivos.h"
#include "Equipamentos.h"
#include <QTableWidgetItem>

NomesCodigos::NomesCodigos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NomesCodigos)
{
    ui->setupUi(this);
    ListarTodos();
}

NomesCodigos::~NomesCodigos()
{
    delete ui;
}

void NomesCodigos::ListarTodos()
{
    IndiceEq E;
    Equipamentos aux;

    for(int i = 0 ; i < E.getqtd() ; i++)
    {
        Arquivos::PegaEquipamento(&aux,E.getPosicaoNoArquivo(i));
        if(!aux.getlixo())
        {
            char nome[80];
            aux.getnome(nome);
            ui->tableWidget->insertRow(i);
            QTableWidgetItem *item1 = new QTableWidgetItem(nome);
            QTableWidgetItem *item2 = new QTableWidgetItem(QString::number(aux.getcodigo()));

            ui->tableWidget->setItem(i,0,item1);
            ui->tableWidget->setItem(i,1,item2);
        }
    }
}
