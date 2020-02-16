#ifndef COLISION_H
#define COLISION_H

#include "TreeAVL.h"
#include "pair.h"
#include "Jogador.h"
#define PEDRA -1
#define MORTO -80

class Colision
{
private:
    TreeAVL<my::pair,int> Tree;

    int limite_linha;

    int limite_coluna;

    Jogador* Jogadores;

    int Num_Jogadores;

private:
     bool ValidaPosicao(int l, int c);

     bool Action_M( int id , int dir);

     bool Action_C( int id , int dir);

     bool Action_D( int id , int dir);

     bool Action_A( int id , int dir);

     void Morte(int id);

     bool Vivo(int id);

     int Prox_jogador(int id);

     void AddJogador(int id,int l,int c,int hp, int dano, int pontosAcao);

     void AddPedra(int l, int c);

     void LimitesMapa(int l, int c);

     void setNumJogadores(int qtd);

     void Reset();

public:
    Colision();

    ~Colision();    

    bool LeituraJogadores();

    void LeituraLimitesMapa();

    void LeituraDasPedras();

    void LeituraComandos_Joga();

    void ImprimirResultados();
};


#endif // COLISION_H
