#include "Aluga.h"
#include <cstring>

Aluga::Aluga()
{
    QuantidadeAlugada = 0;
}

void Aluga::AdicionaAluguel(long long cod, int quantidade_de_equipamentos_alugados)
{
    VetorDeAlugados[QuantidadeAlugada].codigo = cod;
    VetorDeAlugados[QuantidadeAlugada].QtdAlugada = quantidade_de_equipamentos_alugados;
    QuantidadeAlugada++;
}

void Aluga::setCliente(const char *Nome)
{
    strcpy(NomeDoCliente,Nome);
}

void Aluga::setQuantidadeAlugada(int x)
{
    QuantidadeAlugada = x;
}

int Aluga::getQuantidadeAlugada()
{
    return QuantidadeAlugada;
}
