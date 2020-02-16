#ifndef INDICE_H
#define INDICE_H
#include <fstream>
#include "games.h"
#include "lig.h"


class indice
{
private:

  int qtd;
  lig * idgames;

public:
    indice();//carrega no construtor
   ~indice();//grava no destrutor


    int buscab(int pi,int pf,char * nome);// utilitaria
    int buscabinaria(char *nome);//retorna maior que zero caso encontre, e menor que zero caso nao exista
    int gravarid(games *p,int posicao);//gravar um jogo no indice
    int getqtda();//retorna quantos elementos tem no indice
    void ordenar(lig *obj);//ordena o indice toda vez q coloca um jogo nele, caso nao ja exista
    int getposic(char *nome);//retorna a posição no arquivao caso ache, caso nao ache retorna negativo
    void getnome(char *n, int p);//retorna o nome de um obj do vetor de indice
};

#endif // INDICE_H
