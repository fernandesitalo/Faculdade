#include "Equipamentos.h"
#include <cstring>

void Equipamentos::setcodigo(const long long codigo)
{
    this->codigo = codigo;
}

long long Equipamentos::getcodigo()
{
    return codigo;
}

void Equipamentos::setnome(const char *nome)
{
    strcpy(this->nome,nome);
}

void Equipamentos::getnome(char *nome)
{
    strcpy(nome,this->nome);
}

void Equipamentos::setpreco(const float preco)
{
    this->preco = preco;
}

float Equipamentos::getpreco()
{
    return preco;
}

void Equipamentos::setdescricao(const char *descricao)
{
    strcpy(this->descricao,descricao);
}

void Equipamentos::getdescricao(char *descricao)
{
    strcpy(descricao,this->descricao);
}

void Equipamentos::setlixo(bool __true_or_false)
{
    lixo = __true_or_false;
}

bool Equipamentos::getlixo()
{
    return lixo;
}

void Equipamentos::setqtd(int quantidade)
{
   qtd = quantidade;
}

int Equipamentos::getqtd()
{
    return qtd;
}

Equipamentos::Equipamentos()
{
    lixo = false; // cria um objeto equipamento que nao é lixo!
    descricao[0] = 0;
    preco = 0;
    codigo = 0;
    nome[0] = 0;
    qtd = 0;
}
