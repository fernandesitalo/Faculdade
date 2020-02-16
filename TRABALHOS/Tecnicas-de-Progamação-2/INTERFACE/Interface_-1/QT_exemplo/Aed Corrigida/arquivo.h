#ifndef ARQUIVO_H
#define ARQUIVO_H
#include "games.h"

class arquivo
{
public:
    arquivo();

    void gravarF(games *p);///gravar um jogo no final do  arquivo
    void ler(games *p,int pos);/// le de uma posiçao do arquivo
    void sobrescrever(games *p, int pos);///sobrescreve um obj no arquivo
    int getqtda();


};

#endif // ARQUIVO_H
