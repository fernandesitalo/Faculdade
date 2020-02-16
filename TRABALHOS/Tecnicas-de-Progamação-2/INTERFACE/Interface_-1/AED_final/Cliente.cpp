#include "Cliente.h"
#include <string.h>

void Cliente::setnome(const char *nome)
{
    strcpy(this->nome,nome);
}

void Cliente::getnome(char *nome)
{
    strcpy(nome,this->nome);
}

void Cliente::setcpf(const long long cpf)
{
    this->cpf = cpf;
}

long long Cliente::getcpf()
{
    return cpf;
}

void Cliente::setendereco(const char *endereco)
{
    strcpy(this->endereco,endereco);
}

void Cliente::getendereco(char *endereco)
{
    strcpy(endereco,this->endereco);
}

void Cliente::setfone(const long long fone)
{
    this->fone = fone;
}

long long Cliente::getfone()
{
    return fone;
}

void Cliente::setLixo(bool __true_or_false__)
{
    lixo = __true_or_false__;
}

bool Cliente::getlixo()
{
    return lixo;
}

Cliente::Cliente()
{
    nome[0] = '\0';
    cpf = 0;
    endereco[0] = '\0';
    fone = 0;
    lixo = false; /// importante
}
