#ifndef ALUGA_H
#define ALUGA_H

#include "INDALUGA.h"
class Aluga
{
private:
    char NomeDoCliente[80];
    INDALUGA VetorDeAlugados[10];
    int QuantidadeAlugada;
public:
    Aluga();

    void AdicionaAluguel(long long cod, int quantidade_de_equipamentos_alugados);

    void setCliente(const char *Nome);

    void setQuantidadeAlugada(int x);

    int getQuantidadeAlugada();



};

#endif // ALUGA_H
