#include "Lote.h"

Lote::Lote()
{
    proprietario = NULL;
    comprimento = 0;
    frente = 0;
}

void Lote::set_proprietario(Pessoa *A)
{
    this->proprietario = A;
}

Pessoa *Lote::get_proprietario() const
{
    return proprietario;
}

void Lote::set_comprimento(float comprimento)
{
    this->comprimento = comprimento;
}

float Lote::get_comprimento()
{
    return comprimento;
}

void Lote::set_frente(float frente)
{
    this->frente = frente;
}

float Lote::get_frente()
{
    return frente;
}

float Lote::get_area()
{
    return comprimento*frente;
}




