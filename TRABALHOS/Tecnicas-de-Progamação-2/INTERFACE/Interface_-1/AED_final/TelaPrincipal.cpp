#include "TelaPrincipal.h"
#include "ui_TelaPrincipal.h"

#include "CadrastroCliente.h"
#include "AtualizarCliente.h"

#include "CadrastroEquipamento.h"
#include "AtualizarEquipamento.h"
#include <QMessageBox>
#include "AlugarEquipamento.h"
#include "ConsultaAlugueis.h"
TelaPrincipal::TelaPrincipal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TelaPrincipal)
{
    ui->setupUi(this);
    setWindowTitle("----=== MENU PRINCIPAL ====----");
}

TelaPrincipal::~TelaPrincipal()
{
    delete ui;
}



void TelaPrincipal::on_CadrastrarClienteButton_clicked()
{
    CadrastroCliente A;
    this->hide();
    A.exec();
    this->show();
}

void TelaPrincipal::on_AtualizarClienteButton_clicked()
{
    AtualizarCliente A;
    this->hide();
    A.exec();
    this->show();

}

void TelaPrincipal::on_LixeiraButton_clicked()
{
    QMessageBox M;
    // MESSAGEM -- SUA LIXEIRA ESTA SENDO ESVAZIADA;

    Arquivos::EsvaziarLixeiraClientes();
    Arquivos::EsvaziarLixeiraEquipamentos();
    Arquivos::EsvaziarLixeiraAluguel();

    M.information(0," ","Limpeza efetauda com Sucesso!");
}

void TelaPrincipal::on_CadrastroEquipamentosButton_clicked()
{
    CadrastroEquipamento A;
    this->hide();
    A.exec();
    this->show();
}

void TelaPrincipal::on_AtualizarEquipamentoButton_clicked()
{
    AtualizarEquipamento A;
    this->hide();
    A.exec();
    this->show();
}

void TelaPrincipal::on_AlugarButton_clicked()
{
    AlugarEquipamento A;
    this->hide();
    A.exec();
    this->show();
}

void TelaPrincipal::on_AlugarButton_2_clicked()
{
    ConsultaAlugueis A;
    this->hide();
    A.exec();
    this->show();
}

void TelaPrincipal::on_pushButton_clicked()
{
    this->hide();
}
