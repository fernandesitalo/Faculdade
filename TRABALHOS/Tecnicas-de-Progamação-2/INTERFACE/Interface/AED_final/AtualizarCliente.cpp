#include "AtualizarCliente.h"
#include "ui_AtualizarCliente.h"
#include "Arquivos.h"
#include <QMessageBox>
#include "IndiceCl.h"

AtualizarCliente::AtualizarCliente(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AtualizarCliente)
{
    ui->setupUi(this);
    at = new Cliente;
    setWindowTitle("----=== CONSULTAR CLIENTES ====----");
    ListaTodos();
}

AtualizarCliente::~AtualizarCliente()
{
    delete ui;
}

void AtualizarCliente::on_atualizarButton_clicked() // BOTAO ATUALIZAR
{
    QMessageBox Mensagem;
    try
    {
        if(ui->linenome->text().isEmpty() || ui->linefone->text().isEmpty()||ui->lineendereco->text().isEmpty()||ui->linecpf->text().isEmpty())
        {
            throw 1.2;
        }
        if(Mensagem.question(this,"","Realmente deseja Atualizar este cadrastro?",QMessageBox::Yes,QMessageBox::No) == QMessageBox::Yes)
        {
            QMessageBox Mensagem;
            at->setnome(ui->linenome->text().toStdString().c_str());
            at->setcpf(ui->linecpf->text().toLongLong());
            at->setendereco(ui->lineendereco->text().toStdString().c_str());
            at->setfone(ui->linefone->text().toLongLong());

            char NovoNome[80];
            strcpy(NovoNome,ui->linenome->text().toStdString().c_str());

            if(strcmp(NomeOriginal,NovoNome) == 0) // SE NAO TIVER ALTERACOES NO NOME, SOBREESCREVE EM CIMA DO CADRASTRO ORIGINAL
            {
                if(ui->linenome->text().isEmpty() || ui->linecpf->text().isEmpty() || ui->lineendereco->text().isEmpty() || ui->linefone->text().isEmpty())
                {
                    throw 0;
                }
                IndiceCl I;
                char auxNome[80];
                at->getnome(auxNome);

                Arquivos::SobreescreveCliente(at,PosicaoNoArquivo);
                // SobreescreveCliente lanca exessao se der Merda
            }
            else // NOMES DIFRENTES .: ISSO EXIGE UM NOVO CADRASTRO
            {
                /// PRIMEIRO ::: "DELETAR O CADRASTRO ORIGINAL"... MARCAR COMO LIXO
                IndiceCl I;
                I.setLixo(true,I.BuscaNoIndice(NomeOriginal));
                Cliente aux;
                Arquivos::PegaCliente(&aux,PosicaoNoArquivo);
                aux.setLixo(true);
                Arquivos::SobreescreveCliente(&aux,PosicaoNoArquivo);

                /// SEGUNDO ::: EFETUAR UM NOVO CADRASTRO!!!!!!!!! PQ O É UM NOVO NOME, E NOME E A NOSSA CHAVE DE BUSCA!!
                I.InsereOrdenado(at);
                Arquivos::NovoCliente(at);

                ui->listWidget->clear();
                //ListaTodos();

                ui->linenome->clear();
                ui->linefone->clear();
                ui->lineendereco->clear();
                ui->linecpf->clear();

            }
        }
    }

    catch(int e)
    {
        Mensagem.critical(this,"","É necessario que todos Campos estejam Preenchidos!");
    }
    catch(const char* erro)
    {
        Mensagem.critical(this,"","Erro ao Gravar Informaçoes...");
        exit(1);
    }
    catch(...)
    {
        Mensagem.critical(this,"","Preencha todos os campos após selecionar um nome na lista!");
    }


}


void AtualizarCliente::on_listWidget_itemClicked(QListWidgetItem *item)
{
    char auxNome[80];
    strcpy(auxNome,item->text().toStdString().c_str());//copiar da Lista para a variavel auxNome
    IndiceCl I;

    strcpy(NomeOriginal,auxNome);////////////////////////

    PosicaoNoArquivo = I.getPosicaoNoArquivo(auxNome); // retorna a posicao no arquivo
    Cliente X;
    Arquivos::PegaCliente(&X,PosicaoNoArquivo);
    exibeCliente(&X);
}


void AtualizarCliente::exibeCliente(Cliente* P)
{
    char aux[80],aux2[200];
    P->getnome(aux);
    P->getendereco(aux2);
    ui->linenome->setText(QString::fromLatin1(aux));
    ui->linecpf->setText(QString::number(P->getcpf()));
    ui->lineendereco->setText(aux2);
    ui->linefone->setText(QString::number(P->getfone()));
}



void AtualizarCliente::on_comboBox_2_activated(const QString &arg1)
{
    char C[4];
    strcpy(C,arg1.toStdString().c_str());

    if(C[1] == '-')
        ListaTodos();
    else
        listaLetra(C[0]);

}




void AtualizarCliente::ListaTodos()
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

void AtualizarCliente::listaLetra(char caracter)
{
    char caracter2;
    char aux[80];
    ui->listWidget->clear();
    IndiceCl I;
    if(caracter >= 97)
    {
        caracter2 = caracter-32;
    }
    else
    {
        caracter2 = caracter+32;
    }



    for(int i = 0 ; i < I.getqtd() ; i++)
    {
        if(!I.Ehlixo(i))
        {
            I.getNome(aux,i);
            if(caracter == aux[0] || aux[0] == caracter2)
            {
                QListWidgetItem *qlwi = new QListWidgetItem(QString::fromLatin1(aux));
                ui->listWidget->insertItem(i,qlwi);
            }
        }
    }
}




void AtualizarCliente::on_deletarButton_clicked()
{
    QMessageBox Mensagem;

    if(Mensagem.question(this,"","Excluir o cadrastro do(a) " + ui->linenome->text() + "?",QMessageBox::Yes,QMessageBox::No) == QMessageBox::Yes)
    {
        char temp[80];
        strcpy(temp,ui->linenome->text().toStdString().c_str());
        IndiceCl I;
        I.setLixo(true,I.BuscaNoIndice(temp));
        Cliente aux;
        Arquivos::PegaCliente(&aux,I.getPosicaoNoArquivo(temp));
        aux.setLixo(true);
        Arquivos::SobreescreveCliente(&aux,I.getPosicaoNoArquivo(temp));
        ui->listWidget->clear();
        //ListaTodos();

        ui->linenome->clear();
        ui->linefone->clear();
        ui->lineendereco->clear();
        ui->linecpf->clear();
    }
}

void AtualizarCliente::on_cancelarButton_clicked()
{
    QMessageBox Pergunta;

    if(Pergunta.question(this," ","Deseja sair sem salvar alterações?", QMessageBox::Yes|QMessageBox::No) == QMessageBox::Yes)
    {
        this->hide();
    }
}
