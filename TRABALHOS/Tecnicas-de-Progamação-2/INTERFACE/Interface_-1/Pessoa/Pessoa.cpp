#include "Pessoa.h"

Pessoa::Pessoa()
{

}

void Pessoa::set_nome(QString nome)
{
    this->nome = nome;// copia o parametro para o atributo
}

QString Pessoa::get_nome() const
{
    return nome; // retorna o atributo nome
}

void Pessoa::set_email(QString email)
{
    this->email = email;
}

QString Pessoa::get_email() const
{
    return email;
}

void Pessoa::set_cpf(QString cpf)
{
    this->cpf = cpf;
}

QString Pessoa::get_cpf() const
{
    return cpf;
}

