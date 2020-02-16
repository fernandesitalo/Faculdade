#include "INDCL.h"
#include <cstring>

void INDCL::setINDCL(const char *nome, int pos)
{
    strcpy(this->nome,nome);
    this->pos = pos;
}

void INDCL::getNome(char *vetorchar)
{
    strcpy(vetorchar,this->nome);
}

void INDCL::setposicao(int posicao)
{
    pos = posicao;
}



int INDCL::getPosNoArquivo()
{
    return pos;
}


INDCL::INDCL()
{

}
