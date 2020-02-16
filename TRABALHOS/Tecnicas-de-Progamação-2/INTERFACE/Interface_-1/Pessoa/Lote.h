#ifndef LOTE_H
#define LOTE_H

#include "Pessoa.h"

class Lote
{
private:
    Pessoa *proprietario;
    float comprimento;
    float frente;

public:
    Lote();

    void set_proprietario(Pessoa* A);
    Pessoa* get_proprietario() const;

    void set_comprimento(float comprimento);
    float get_comprimento();

    void set_frente(float frente);
    float get_frente();

    float get_area();
};

#endif // LOTE_H
