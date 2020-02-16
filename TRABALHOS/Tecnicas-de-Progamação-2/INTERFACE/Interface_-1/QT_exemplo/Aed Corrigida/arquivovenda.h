#ifndef ARQUIVOVENDA_H
#define ARQUIVOVENDA_H
#include "vendas.h"

class arquivovenda
{
public:
    arquivovenda();


    void gravarF(vendas *p);///gravar um jogo no final do  arquivo
    void ler(vendas *p,int pos);/// le de uma posiçao do arquivo
    void sobrescrever(vendas *p, int pos);///sobrescreve um obj no arquivo
    int getqtda();
};

#endif // ARQUIVOVENDA_H
