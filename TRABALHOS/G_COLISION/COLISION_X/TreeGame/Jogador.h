#ifndef JOGADOR_H
#define JOGADOR_H
#include "pair.h"

class Jogador
{
public:
    int hp;
    int dano;
    int linha;
    int coluna;
    int PontosAcao;
    bool vivo;
public:
    Jogador(){hp = dano = linha = coluna = PontosAcao = 0; vivo = true;}
};
#endif // JOGADOR_H
