#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "Pessoa.h"
#include "Lote.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->p = new Pessoa();
    this->l = new Lote();
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*
void MainWindow::on_NOME_returnPressed()
{
    this->p->set_nome(ui->NOME->text());
 //   ui->EMAIL->setFocus();
 //   ui->EMAIL->selectAll();
}

void MainWindow::on_EMAIL_returnPressed()
{
    this->p->set_email(ui->EMAIL->text());
    ui->LARGURA->setFocus();
    ui->LARGURA->selectAll();
}

void MainWindow::on_LARGURA_returnPressed()
{
    this->l->set_comprimento(ui->LARGURA->text().toFloat());
    ui->FRENTE->setFocus();
    ui->FRENTE->selectAll();
}

void MainWindow::on_FRENTE_returnPressed()
{
    this->l->set_frente(ui->FRENTE->text().toFloat());
    ui->pushButton->setFocus();
    this->on_pushButton_clicked();
}*/


void MainWindow::on_pushButton_clicked()
{

    this->p->set_nome(ui->NOME->text());
     this->p->set_email(ui->EMAIL->text());
     this->l->set_comprimento(ui->LARGURA->text().toFloat());
    this->l->set_frente(ui->FRENTE->text().toFloat());


    QString resposta;


            resposta = "Proprietario: "+ p->get_nome() +"\n"+p->get_email()+"\nLote: \n - Frente:"+ QString::number(l->get_frente());
            resposta += "\n - Comprimento: "+QString::number(l->get_comprimento())+"\nAREA:";
            resposta += QString::number(l->get_area());

            ui->textBrowser->clear();
            ui->textBrowser->setText(resposta);
            ui->NOME->setFocus();
            ui->NOME->selectAll();
}
