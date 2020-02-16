#include "CadrastroCliente.h"
#include "ui_CadrastroCliente.h"

#include <QMessageBox>
#include "IndiceCl.h"

CadrastroCliente::CadrastroCliente(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CadrastroCliente)
{
    CL = new Cliente;
    ui->setupUi(this);
    setWindowTitle("----=== CADRASTRO DE CLIENTES ====----");
}

CadrastroCliente::~CadrastroCliente()
{
    delete CL;
    delete ui;
}

void CadrastroCliente::on_cadrastrarButton_clicked()
{
    QMessageBox Mensagem;

    CL->setnome(ui->linenome->text().toStdString().c_str());
    CL->setcpf(ui->linecpf->text().toLongLong());
    CL->setendereco(ui->lineendereco->text().toStdString().c_str());
    CL->setfone(ui->linefone->text().toLongLong());

    ///------------------"VALIDAR DADOS"***campos em braco****nomes ja cadrastrados***-----------///
    try
    {
        if(ui->linenome->text().isEmpty() || ui->linecpf->text().isEmpty() || ui->lineendereco->text().isEmpty() || ui->linefone->text().isEmpty())
        {
            throw 0;
        }

        IndiceCl I;

        char aux[80];
        CL->getnome(aux);

        if(!I.VerificaUnicidadeNome(aux)) //  O NOME E UNICO? SIM ELE E UNICO!!
        {
            throw "erro";
        }
        I.InsereOrdenado(CL);      // insere no indice
        Arquivos::NovoCliente(CL); // grava no arquivo o novo cliente que acabou de ser cadrastrado
        // lembrar que em NovoCliente existe um thow
        QMessageBox::information(this,"","Cliente Cadrastrado com sucesso!");
        ui->linecpf->clear();
        ui->lineendereco->clear();
        ui->linenome->clear();
        ui->linefone->clear();
    }
    catch(int USUARIOTROLL)
    {
        Mensagem.critical(this,"ATENCAO!!","PREENCHA TODOS CAMPOS!!!!");
    }
    catch(const char *ERRONOCADRASTRO)
    {
        Mensagem.critical(this,"AVISO","Cliente já Cadrastrado!!");
    }
    catch(...)
    {
        Mensagem.critical(this,"","Erro ao Gravar Informações, Contate o suporte Tecnico!");
    }
    ///----------------------------------------------------------------------------------------///
}

void CadrastroCliente::on_cancelarButton_clicked()
{
    this->hide();
}
