#include "AlugarEquipamento.h"
#include "ui_AlugarEquipamento.h"
#include <QMessageBox>
#include "IndiceEq.h"
#include "IndiceCl.h"
#include "IndiceAl.h"
#include "Arquivos.h"
#include <QTableWidgetItem>
#include "NomesCodigos.h"

AlugarEquipamento::AlugarEquipamento(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AlugarEquipamento)
{
    ui->setupUi(this);
    Pedido = new INDALUGA;
    qtd = 0;
    soma = 0;
    IndiceAl A;
    ui->lineEdit->setText(QString::number(A.getCodigoDoAluguel()));
    listarTodos();
    setWindowTitle("----=== ALUGUEL DE EQUIPAMENTOS ====----");
}

AlugarEquipamento::~AlugarEquipamento()
{
    delete ui;
}

void AlugarEquipamento::on_InserirButton_clicked()
{
    QMessageBox show;
    try
    {
        if(ui->qtdedit->text().isEmpty() || ui->linecodigo->text().isEmpty())
        {
            throw 1.2;
        }

        IndiceEq I;
        Equipamentos aux;
        long long cod = ui->linecodigo->text().toLongLong();

        int posicao = I.PosicaoNoArquivo(cod);

        if(posicao < 0)
            throw 10;

        int QTD = ui->qtdedit->text().toInt();

        Arquivos::PegaEquipamento(&aux,posicao);

        char nome[80];
        aux.getnome(nome);// NOME DO EQUIPAMENTO

        int i;
        for(i = 0 ; i < qtd && cod != eqs[i]; i++); // SE O EQUIPAMENTO JA FOI INSERIDO NA LISTA DO PEDIDO..... OU ATUALIA O PEDIDO OU DEIXA QUETO...
        if(cod == eqs[i] && qtd != 0)
        {
            if(show.question(this,"","Este equipamento já foi inserido... Deseja alterar a quantidade a ser alugada?",
                             QMessageBox::Yes,QMessageBox::No) == QMessageBox::Yes)
            {
                ui->tableWidget->removeRow(i);

                if(aux.getqtd() >= QTD)
                {
                    ui->tableWidget->insertRow(i);
                    QTableWidgetItem *item1 = new QTableWidgetItem(nome);
                    QTableWidgetItem *item2 = new QTableWidgetItem(QString::number(QTD));
                    QTableWidgetItem *item3 = new QTableWidgetItem(QString::number(aux.getpreco()*QTD));
                    soma -= aux.getpreco()*Pedido->getQuantidadeAlugada(i);
                    soma += aux.getpreco()*QTD;
                    ui->tableWidget->setItem(i,0,item1);
                    ui->tableWidget->setItem(i,1,item2);
                    ui->tableWidget->setItem(i,2,item3);
                    ui->linePrecoTotoal->setText(QString::number(soma));
                    Pedido->AlteraQuantidade(i,QTD);
                }
            }
            return;
        }


        if(show.question(this," ","Adicionar "+QString::number(QTD)+" "+nome + "(s) ?",QMessageBox::Yes|QMessageBox::No) == QMessageBox::Yes)
        {
            if(qtd >= 10)
                throw "Erro";

            if(aux.getqtd() >= ui->qtdedit->text().toInt())
            {
                ui->tableWidget->insertRow(qtd);
                QTableWidgetItem *item1 = new QTableWidgetItem(nome);
                QTableWidgetItem *item2 = new QTableWidgetItem(QString::number(QTD));
                QTableWidgetItem *item3 = new QTableWidgetItem(QString::number(aux.getpreco()*QTD));
                soma = soma + aux.getpreco()*QTD;
                ui->tableWidget->setItem(qtd,0,item1);
                ui->tableWidget->setItem(qtd,1,item2);
                ui->tableWidget->setItem(qtd,2,item3);
                ui->linePrecoTotoal->setText(QString::number(soma));
                Pedido->AdicionaEquipamento(cod,QTD);
                eqs[qtd] = cod;
                qtd++;

            }
            else
            {
                show.information(this," "," Quandidade de Estoque Indisponivel!");
            }
        }
    }
    catch(const char *a)
    {
        QMessageBox::warning(this,"","Voce so pode alugar 10 equipamentos, se contente!");
    }
    catch(int erro)
    {
        show.warning(this,"","Equipamento nao encontrado");

    }
    catch(...)
    {
        QMessageBox::warning(this,"","Campos Vazios!");
    }
}

void AlugarEquipamento::on_finalizarButton_clicked()
{
    QMessageBox Mensagem;
    IndiceCl I;
    IndiceAl A;
    if(qtd == 0)
    {
        Mensagem.warning(this,"","Você nao pode alugar 0 Equipamentos! Escolha pelo menos um!");
    }
    else
    {
        try
        {
            if(ui->linecliente->text().isEmpty() || ui->linecodigo->text().isEmpty())
            {
                throw 'a';
            }

            long long X = ui->lineEdit->text().toLongLong();
            if(!A.VerificarUnicidadeCodigo(X))
            {
                throw 1.2;
            }

            Pedido->setCodigoDoAluguel(X);

            if(I.VerificaUnicidadeNome(ui->linecliente->text().toStdString().c_str()))
            {
                throw 10;
            }

            Pedido->setNomeDoCliente(ui->linecliente->text().toStdString().c_str());
            Pedido->setPrecoTotal(soma);
            A.setCodigoDoAluguel(ui->lineEdit->text().toLongLong());
            IndiceEq E;
            Equipamentos aux;
            for(int i = 0 ; i < qtd ; i++)
            {
                int temp = E.PosicaoNoArquivo(Pedido->getCodigo(i));

                Arquivos::PegaEquipamento(&aux,temp);

                aux.setqtd(aux.getqtd() - Pedido->getQuantidadeAlugada(i));

                Arquivos::SobreescreveEquipamento(&aux,temp);
            }

            Arquivos::NovoAluguel(Pedido);
            A.InserirOrdenadamenteAluguel(*Pedido);

            limpaTabela();

            Pedido->setQtdDeEqAlugados(0);
            qtd = 0;
            soma = 0;
            ui->lineEdit->setText(QString::number(A.getCodigoDoAluguel()));
            ui->linecodigo->clear();
            ui->qtdedit->clear();
            ui->linecliente->setText("Nome do Cliente");
            ui->linePrecoTotoal->setText("R$ ");

            Mensagem.information(this," ","Aluguel Realizado com Sucesso!");
        }
        catch(float A)
        {
            Mensagem.warning(this,"","Codigo do Aluguel já Existente ou Invalido!");
        }
        catch(int NOMEERRADO)
        {
            Mensagem.warning(this,"","Cliente Nao encontrado!Verifique a grafia...");
        }
        catch(char a)
        {
            Mensagem.warning(this,"Atenção!","Todos os campos são obrigatorios!");
        }
        catch(...)
        {
            Mensagem.information(this,"","Memoria Insuficiente");
        }
    }
}

void AlugarEquipamento::limpaTabela()
{
    for(int i = qtd-1 ; i >= 0; i--)
        ui->tableWidget->removeRow(i);
}

void AlugarEquipamento::listarTodos()
{
    char aux[80];
    ui->listWidget->clear();

    IndiceCl I;
    for(int i = 0 ; i < I.getqtd() ; i++)
    {
        if(!I.Ehlixo(i))
        {
            I.getNome(aux,i);
            QListWidgetItem *qlwi = new QListWidgetItem(QString::fromLatin1(aux));
            ui->listWidget->insertItem(i,qlwi);
        }
    }
}

void AlugarEquipamento::on_listWidget_itemClicked(QListWidgetItem *item)
{
    ui->linecliente->setText(item->text().toStdString().c_str());
}


void AlugarEquipamento::on_DeletButton_clicked()
{
    QMessageBox M;
    try
    {
        if(ui->LineCodDelet->text().isEmpty())//
            throw 10;


        IndiceEq E;
        Equipamentos aux;
        long long cod = ui->LineCodDelet->text().toLongLong();

        int posicao = E.PosicaoNoArquivo(cod);

        if(posicao < 0)
            throw 'a';


        int linha = Pedido->BuscaEquipamentoNoPedido(cod);
        if(linha < 0)
        {
            QMessageBox::information(this,"","Este equipamento não foi Inserido no Pedido...");
        }
        else
        {


            Arquivos::PegaEquipamento(&aux,posicao);
            char nome[80];
            aux.getnome(nome);// NOME DO EQUIPAMENTO



            if(M.question(this,"","Realmente Deseja retirar "+QString::number(Pedido->getQuantidadeAlugada(linha))+" "+ nome +"(s)"+" do seu Pedido?",
                                    QMessageBox::Yes|QMessageBox::No) == QMessageBox::Yes)
            {
                soma -= Pedido->getQuantidadeAlugada(linha)*aux.getpreco();
                Pedido->RetiraEquipamento(linha);
                ui->tableWidget->removeRow(linha);



                ui->linePrecoTotoal->setText("R$" + QString::number(soma));
                qtd--;
            }

        }

    }

    catch(int erro)
    {
        QMessageBox::warning(this,"","Campo Vazio!");
    }
    catch(char a)
    {
        QMessageBox::warning(this,"","Esse equipamento não existe!");
    }
}

void AlugarEquipamento::on_pushButton_2_clicked()
{
    NomesCodigos A;
    A.exec();
}

void AlugarEquipamento::on_pushButton_clicked()
{
    NomesCodigos A;
    A.exec();
}

void AlugarEquipamento::on_finalizarButton_2_clicked()
{
    IndiceAl A;
    if(QMessageBox::question(this,"","Realmente deseja cancelar este aluguel?",QMessageBox::Yes,QMessageBox::No) == QMessageBox::Yes)
    {
        limpaTabela();
        Pedido->setQtdDeEqAlugados(0);
        qtd = 0;
        soma = 0;
        ui->lineEdit->setText(QString::number(A.getCodigoDoAluguel()));
        ui->linecodigo->clear();
        ui->qtdedit->clear();
        ui->linecliente->setText("Nome do Cliente");
        ui->linePrecoTotoal->setText("R$ ");

    }
}

void AlugarEquipamento::on_finalizarButton_3_clicked()
{
    this->hide();
}
