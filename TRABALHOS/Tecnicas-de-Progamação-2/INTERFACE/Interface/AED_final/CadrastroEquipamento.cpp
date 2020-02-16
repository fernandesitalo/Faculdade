#include "CadrastroEquipamento.h"
#include "ui_CadrastroEquipamento.h"
#include <QMessageBox>
#include <IndiceEq.h>
#include "Arquivos.h"

CadrastroEquipamento::CadrastroEquipamento(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CadrastroEquipamento)
{
    EQ = new Equipamentos;
    ui->setupUi(this);
    setWindowTitle("----=== CADRASTRO DE EQUIPAMENTOS ====----");
}

CadrastroEquipamento::~CadrastroEquipamento()
{
    delete ui;
}

void CadrastroEquipamento::on_cadrastrarButton_clicked()
{
    QMessageBox Mensagem;

    EQ->setnome(ui->linenome->text().toStdString().c_str());
    EQ->setcodigo(ui->linecodigo->text().toLongLong());
    EQ->setpreco(ui->linepreco->text().toFloat());
    EQ->setdescricao(ui->linedescricao->text().toStdString().c_str());
    EQ->setqtd(ui->linequantidade->text().toInt());


    ///------------------"VALIDAR DADOS"***campos em braco****nomes ja cadrastrados***-----------///
    try
    {
        if(ui->linenome->text().isEmpty() || ui->linecodigo->text().isEmpty() || ui->linedescricao->text().isEmpty() || ui->linepreco->text().isEmpty())
        {
            throw 0;
        }

        IndiceEq I;

        if(!I.VerificaUnicidadeCodigo(EQ->getcodigo())) //  O NOME E UNICO? SIM ELE E UNICO!!
        {
            throw "erro";
        }
        I.InsereEqOrdenadoIndice(EQ);  // insere no indice
        Arquivos::NovoEquipamento(EQ); // grava no arquivo o novo cliente que acabou de ser cadrastrado
        // lembrar que em NovoCliente existe um thow
        QMessageBox::information(this,"","Cadrastro realizado com Sucesso!");
        ui->linecodigo->clear();
        ui->linedescricao->clear();
        ui->linenome->clear();
        ui->linepreco->clear();
        ui->linequantidade->clear();
    }
    catch(int USUARIOTROLL)
    {
        Mensagem.critical(this,"ATENCAO!","Preencha todos os campos!");
    }
    catch(const char* ERRONOCADRASTRO)
    {
        Mensagem.critical(this,"AVISO","Equipamento já Cadrastrado!");
    }
    catch(...)
    {
        Mensagem.critical(this,"","Erro ao Gravar Informações, Contate o suporte Tecnico!");
    }
    ///----------------------------------------------------------------------------------------///
}

void CadrastroEquipamento::on_cancelarButton_clicked()
{
    this->hide();
}
