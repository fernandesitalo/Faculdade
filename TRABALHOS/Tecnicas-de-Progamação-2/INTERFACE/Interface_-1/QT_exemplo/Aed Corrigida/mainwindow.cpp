#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cadastro.h"
#include "arquivo.h"
#include "consulta.h"
#include "ui_consulta.h"

///colocar para mostrar no estoque apenas os que tem qtd > que 0
/// apagar algo da lista de compras
/// imprimir relação da lista de compras
/// recolocar no aruivo caso seja cancelado da lista de compras
/// emitir nota fiscal
///coolocar arquivo nao util
/// apagar lixeira


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    this->hide();
    cadastro janelak;
    janelak.setGeometry(this->geometry());
    janelak.exec();
    this->setGeometry(janelak.geometry());
    this->show();
}

void MainWindow::on_venda_clicked()
{
    this->hide();
    venda janelav;
    janelav.setGeometry(this->geometry());
    janelav.exec();
    this->setGeometry(janelav.geometry());
    this->show();
}

void MainWindow::on_Consulta_clicked()
{
    consulta obj;
    obj.setGeometry(this->geometry());
    this->hide();
    obj.exec();
    this->setGeometry(obj.geometry());
    this->show();

}

void MainWindow::on_Consulta_3_clicked()
{
    estoque n;
    this->hide();
    n.setGeometry(this->geometry());
    n.exec();
    n.show();
    this->setGeometry(n.geometry());
    this->show();
}
