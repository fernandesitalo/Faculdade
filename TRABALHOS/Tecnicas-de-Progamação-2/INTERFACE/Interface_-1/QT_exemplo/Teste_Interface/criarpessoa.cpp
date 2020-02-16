#include "criarpessoa.h"
#include "ui_criarpessoa.h"

CriarPessoa::CriarPessoa(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CriarPessoa)
{
    ui->setupUi(this);
}

void CriarPessoa::setPessoa(Pessoa *P)
{
    this->P = P;
}

CriarPessoa::~CriarPessoa()
{
    delete ui;
}

void CriarPessoa::on_pushButton_clicked()
{
    P->setCpf(ui->lineCpf->text().toLongLong());
    P->setNome(ui->lineNome->text().toStdString().c_str());
    P->setEndereco(ui->lineEndereco->text().toStdString().c_str());
    P->setIdade(ui->lineIdade->text().toInt());
    P->setTelefone(ui->lineTelefone->text().toStdString().c_str());
    this->close();
}
