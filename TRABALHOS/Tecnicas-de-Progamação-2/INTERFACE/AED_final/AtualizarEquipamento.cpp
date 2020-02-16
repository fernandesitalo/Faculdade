#include "AtualizarEquipamento.h"
#include "ui_AtualizarEquipamento.h"

#include "IndiceEq.h"
#include "Arquivos.h"
#include <QMessageBox>

AtualizarEquipamento::AtualizarEquipamento(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AtualizarEquipamento)
{
    ui->setupUi(this);
    EQ = new Equipamentos;
    listaTodos();
    setWindowTitle("----=== CONSULTAR EQUIPAMENTOS ====----");
}

AtualizarEquipamento::~AtualizarEquipamento()
{
    delete ui;
}

void AtualizarEquipamento::on_BuscaButton_clicked()
{
    QMessageBox Menssagem;
    try
    {
        IndiceEq I;

        if(ui->lineCOD->text().isEmpty())
        {
            throw 'a';
        }
        if( I.BuscaNoIndice(ui->lineCOD->text().toLongLong()) < 0)
        {
            throw 10;
        }
        else
        {
            int A = I.PosicaoNoArquivo(ui->lineCOD->text().toLongLong());

            Equipamentos Aux;

            Arquivos::PegaEquipamento(&Aux,A);

            ExibeEquipamento(&Aux);
        }
    }
    catch(char a)
    {
        Menssagem.critical(this,"Ops!","Pesquisa Invalida!");
    }
    catch(int a)
    {
        Menssagem.critical(this,"OPS!","Codigo incorreto ou inesxistente!");
    }
}

void AtualizarEquipamento::ExibeEquipamento(Equipamentos *P)
{
    CodigoOriginal = P->getcodigo();
    char aux2[200];
    P->getnome(nome);
    P->getdescricao(aux2);
    ui->linenome->setText(QString::fromLatin1(nome));
    ui->linecodigo->setText(QString::number(P->getcodigo()));
    ui->linedescricao->setText(aux2);
    ui->linepreco->setText(QString::number(P->getpreco()));
    ui->lineqtd->setText(QString::number(P->getqtd()));
}

void AtualizarEquipamento::on_listWidget_itemClicked(QListWidgetItem *item)
{
    IndiceEq I;

    int PosicaoNoArquivo = I.PosicaoNoArquivo(item->text().toLongLong()); // retorna a posicao no arquivo
    Equipamentos X;
    Arquivos::PegaEquipamento(&X,PosicaoNoArquivo);
    ExibeEquipamento(&X);

}

void AtualizarEquipamento::listaTodos()
{
    ui->listWidget->clear();

    IndiceEq I;

    for(int i = 0 ; i < I.getqtd() ; i++)
    {
        if(!I.Ehlixo(i))
        {
            QListWidgetItem *qlwi = new QListWidgetItem(QString::number(I.getcodigo(i)));
            ui->listWidget->insertItem(i,qlwi);
        }
    }
}
void AtualizarEquipamento::on_cancelarButton_clicked()
{
    QMessageBox M;

    if(M.question(this," ","Deseja sair sem salvar alterações?",
                  QMessageBox::Yes|QMessageBox::No) == QMessageBox::Yes)

    {
        this->hide();
    }
}

void AtualizarEquipamento::on_atualizarButton_clicked()
{
    IndiceEq I;
    QMessageBox Mensagem;

    EQ->setnome(ui->linenome->text().toStdString().c_str());
    EQ->setdescricao(ui->linedescricao->text().toStdString().c_str());
    EQ->setpreco(ui->linepreco->text().toFloat());
    EQ->setcodigo(ui->linecodigo->text().toLongLong());
    EQ->setqtd(ui->lineqtd->text().toInt());


    try
    {
        if( ui->linecodigo->text().toLongLong() != 0)
            throw 10;

        if(CodigoOriginal == EQ->getcodigo() ) // SE NAO TIVER ALTERACOES NO CODIGO, SOBREESCREVE EM CIMA DO CADRASTRO ORIGINAL
        {
            QMessageBox Mensagem;

            if(ui->linenome->text().isEmpty() || ui->linecodigo->text().isEmpty() || ui->linepreco->text().isEmpty())
            {
                throw 0;
            }

            Arquivos::SobreescreveEquipamento(EQ,I.PosicaoNoArquivo(EQ->getcodigo()));
            // SobreescreveCliente lanca exessao se der Merda
        }
        else // CODIGO DIFRENTES .: ISSO EXIGE UM NOVO CADRASTRO
        {

            if(!I.VerificaUnicidadeCodigo(EQ->getcodigo()))
            {
                throw 0.5;
            }
            /// PRIMEIRO ::: "DELETAR O CADRASTRO ORIGINAL"... MARCAR COMO LIXO


            Equipamentos aux;

            int PosicaoNoArquivo = I.PosicaoNoArquivo(CodigoOriginal);
            aux.setlixo(true);
            I.setLixo(true,I.BuscaNoIndice(CodigoOriginal));

            Arquivos::SobreescreveEquipamento(&aux,PosicaoNoArquivo);

            /// SEGUNDO ::: EFETUAR UM NOVO CADRASTRO!!!!!!!!! PQ O É UM NOVO NOME, E NOME E A NOSSA CHAVE DE BUSCA!!
            I.InsereEqOrdenadoIndice(EQ);
            Arquivos::NovoEquipamento(EQ);
        }

    }
    catch(int e)
    {
        Mensagem.critical(this,"","Os campos identificados com ** são obrigatorios!");
    }
    catch(const char* erro)
    {
        Mensagem.critical(this,"","Erro ao Gravar Informaçoes...");
    }
    catch(...)
    {
        Mensagem.warning(this,"Ops!","Codigo já existente ou campos vazios!");
    }


    ui->listWidget->clear();

    ui->linenome->clear();
    ui->linedescricao->clear();
    ui->linecodigo->clear();
    ui->linepreco->clear();
    ui->lineqtd->clear();

}

void AtualizarEquipamento::on_ApagarButton_clicked()
{
    QMessageBox Mensagem;
    QString aux = nome;

    try
    {
        if(Mensagem.question(this,"","Excluir o cadrastro do(a) " + aux + "?",QMessageBox::Yes,QMessageBox::No) == QMessageBox::Yes)
        {
            /// PRIMEIRO ::: "DELETAR O CADRASTRO ORIGINAL"... MARCAR COMO LIXO
            IndiceEq I;

            I.setLixo(true,I.BuscaNoIndice(CodigoOriginal));// no indice
            Equipamentos aux;

            int PosicaoNoArquivo = I.PosicaoNoArquivo(CodigoOriginal);

            aux.setlixo(true);
            Arquivos::SobreescreveEquipamento(&aux,PosicaoNoArquivo); // no arquivo

            Mensagem.information(this," ","Cadrastro Apagado com sucesso!");

            ui->listWidget->clear();
            ui->linenome->clear();
            ui->linedescricao->clear();
            ui->linecodigo->clear();
            ui->linepreco->clear();
            ui->lineqtd->clear();
        }
    }
    catch(int a)
    {
        Mensagem.critical(this,"","Selecione um Cadrastro para Exclui-lo!");
    }
}

void AtualizarEquipamento::on_ListarButton_clicked()
{
    listaTodos();
}
