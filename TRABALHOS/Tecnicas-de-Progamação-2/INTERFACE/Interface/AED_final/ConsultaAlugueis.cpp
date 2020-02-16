#include "ConsultaAlugueis.h"
#include "ui_ConsultaAlugueis.h"

#include "IndiceAl.h"
#include "Equipamentos.h"
#include "IndiceEq.h"
#include <QTableWidgetItem>
#include "Arquivos.h"
#include <QMessageBox>
ConsultaAlugueis::ConsultaAlugueis(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConsultaAlugueis)
{
    ui->setupUi(this);
    ListarTodos();
    setWindowTitle("----=== CONSULTAR ALUGUEIS ====----");
}

ConsultaAlugueis::~ConsultaAlugueis()
{
    delete ui;
}

void ConsultaAlugueis::ListarTodos()
{
    IndiceAl A;
    ui->listWidget->clear();

    for(int i = 0 ; i < A.getqtd(); i++)
    {
        if(!A.ehLixo(i))
        {
            QListWidgetItem *qlwi = new QListWidgetItem(QString::number(A.getCodigoDoAluguel(i)));
            ui->listWidget->insertItem(i,qlwi);
        }
    }
}

void ConsultaAlugueis::on_listWidget_itemClicked(QListWidgetItem *item)
{
    try
    {
        IndiceAl A;
        int PosicaoNoArquivo = A.PosicaoNoArquivo(item->text().toLongLong()); // retorna a posicao no arquivo
        ////// ARRUMAR ISSO AQUI
        if(PosicaoNoArquivo < 0)
            throw 10;

        INDALUGA X;
        Arquivos::PegaAluguel(&X,PosicaoNoArquivo);
        ExibeNaTela(&X);
    }
    catch(int a)
    {
        QMessageBox::warning(this,"","Fatal error 404");
        exit(1);
    }
}

void ConsultaAlugueis::ExibeNaTela(INDALUGA *X)
{
    limpaTabela();
    char aux[80];
    X->getNomeCliente(aux);
    codAluguel = X->CodigoDoAluguel;
    ui->lineEdit->setText(aux);
    ui->Preco->setText("R$ "+QString::number(X->getPrecoTotal()));
    Equipamentos EQ;
    IndiceEq E;
    int posicao;

    for(int i = 0 ; i < X->QtdDeEqAlugados ; i++)
    {
        ui->tableWidget->insertRow(i);

        posicao = E.BuscaNoIndice(X->getCodigo(i));
        Arquivos::PegaEquipamento(&EQ,posicao);
        EQ.getnome(aux);

        QTableWidgetItem *item1 = new QTableWidgetItem(aux);
        QTableWidgetItem *item2 = new QTableWidgetItem(QString::number(X->getQuantidadeAlugada(i)));
        QTableWidgetItem *item3 = new QTableWidgetItem(QString::number(EQ.getpreco() * X->getQuantidadeAlugada(i)));

        ui->tableWidget->setItem(i,0,item1);
        ui->tableWidget->setItem(i,1,item2);
        ui->tableWidget->setItem(i,2,item3);
    }
}

void ConsultaAlugueis::limpaTabela()
{
    for(int i = 10 ; i >= 0; i--)
        ui->tableWidget->removeRow(i);
}


void ConsultaAlugueis::on_DevolucaoButton_clicked()
{
    QMessageBox M;
    try
    {
        if(ui->lineEdit->text().isEmpty())
        {
            throw 10;
        }

        if(M.question(this,"","Confirmar devolução desdes equipamentos?",QMessageBox::Yes,QMessageBox::No) == QMessageBox::Yes)
        {
            IndiceAl A;
            int posicao = A.PosicaoNoArquivo(codAluguel);
            A.setLixo(true,posicao);
        }

        ui->listWidget->clear();
        limpaTabela();
        ui->Preco->clear();
        ui->lineEdit->clear();
    }
    catch(int a)
    {
        M.warning(this,"","Nenhum Aluguel foi selecionado!");
    }

}

void ConsultaAlugueis::on_pushButton_2_clicked()
{
    ui->listWidget->clear();
    ListarTodos();
}

void ConsultaAlugueis::on_pushButton_clicked()
{
    this->hide();
}
