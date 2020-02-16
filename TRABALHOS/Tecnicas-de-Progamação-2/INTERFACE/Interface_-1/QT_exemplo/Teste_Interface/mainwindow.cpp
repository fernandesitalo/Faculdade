#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <fstream>
#include <QTableWidgetItem>
#include <iostream>
#include "criarpessoa.h"
#include "pessoa.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    NPessoas = 0;
    Pessoa Aux;
    fstream ArquivoEntrada("data.data", ios::in|ios::binary);
    if (ArquivoEntrada.is_open())
        while (ArquivoEntrada.read((char*)&Aux, sizeof(Pessoa)), !ArquivoEntrada.eof()){
            insereNaTabela(Aux);
        }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    Pessoa P;
    CriarPessoa cp;
    cp.setPessoa(&P);
    this->hide();
    cp.exec();
    this->show();

    fstream ArquivoSaida("data.data", ios::app|ios::binary);
    ArquivoSaida.write((char*)&P, sizeof(P));
    ArquivoSaida.close();

    insereNaTabela(P);

}

void MainWindow::insereNaTabela(Pessoa P)
{
    if (NPessoas < 20){
        QListWidgetItem *qlwi = new QListWidgetItem(QString::fromLatin1(P.getNome()));
        ui->listWidget->insertItem(NPessoas, qlwi);
        Pessoas[NPessoas++] = P;
    }
}

void MainWindow::exibePessoa(Pessoa P)
{
    ui->lineCpf->setText(QString::number(P.getCpf()));
    ui->lineEndereco->setText(QString::fromLatin1(P.getEndereco()));
    ui->lineIdade->setText(QString::number(P.getIdade()));
    ui->lineNome->setText(QString::fromLatin1(P.getNome()));
    ui->lineTelefone->setText(QString::fromLatin1(P.getTelefone()));
}

void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
    exibePessoa(Pessoas[ui->listWidget->currentRow()]);
}
