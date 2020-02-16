#include "pessoa.h"
#include "string.h"

void Pessoa::setNome(const char *nome)
{
    strcpy(this->nome, nome);
}

void Pessoa::setEndereco(const char *endereco)
{
    strcpy(this->endereco,endereco);
}

void Pessoa::setTelefone(const char *telefone)
{
    strcpy(this->telefone, telefone);
}

void Pessoa::setCpf(unsigned long long cpf)
{
    this->cpf = cpf;
}

void Pessoa::setIdade(int idade)
{
    this->idade = idade;
}

char *Pessoa::getNome()
{
    return nome;
}

char *Pessoa::getEndereco()
{
    return endereco;
}

char *Pessoa::getTelefone()
{
    return telefone;
}

unsigned long long Pessoa::getCpf()
{
    return cpf;
}

int Pessoa::getIdade()
{
    return idade;
}
