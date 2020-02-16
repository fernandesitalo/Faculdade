#include "INDEQ.h"

void INDEQ::setINDEQ(long long codigo, int posicao)
{
    cod = codigo;
    pos = posicao;
}

long long INDEQ::getcodigoEq()
{
    return pos;
}

INDEQ::INDEQ()
{
    lixo = false; // criar um objeto da classe indice que nao é um lixo
}
