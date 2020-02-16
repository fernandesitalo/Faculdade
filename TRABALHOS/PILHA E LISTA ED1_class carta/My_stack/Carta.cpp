#include "Carta.h"

void Carta::set_carta(int valor_, char naipe_)
{
    valor = valor_;
    naipe = naipe_;
}

void Carta::get_carta(int *valor_, char *naipe_)
{
    *valor_ = valor;
    *naipe_ = naipe;
}

Carta::Carta()
{
}
