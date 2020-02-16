#include "NomeCodigo.h"
#include "ui_NomeCodigo.h"
#include <QTableWidgetItem>
#include "IndiceEq.h"
#include "Arquivos.h"

NomeCodigo::NomeCodigo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NomeCodigo)
{
    ui->setupUi(this);

    listarTodos();
}

NomeCodigo::~NomeCodigo()
{
    delete ui;
}

void NomeCodigo::listarTodos()
{
    IndiceEq E;
    INDEQ aux;
    for(int i = 0 ; i < E.getqtd() ; i++)
    {

        Arquivos::PegaEquipamento(&aux,i);

        if()


        ui->tableWidget->insertRow(i);

        QTableWidgetItem *item1 = new QTableWidgetItem(nome);
        QTableWidgetItem *item2 = new QTableWidgetItem(QString::number(cod));


        ui->tableWidget->setItem(qtd,0,item1);
        ui->tableWidget->setItem(qtd,1,item2);

    }
}
