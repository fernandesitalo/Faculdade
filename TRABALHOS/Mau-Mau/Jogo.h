#ifndef JOGO_H
#define JOGO_H

#include "stack.h"
#include "queue.h"
#include "ListDoubleCycle.h"
#include "ListSortedSimple.h"
#include "Carta.h"
#include <stdio.h>
#include <iostream>
using namespace std;
using namespace my;

typedef ListSortedSimple<Carta> list;
typedef ListDoubleCycle<list> cycle;

class Jogo
{
private:
    bool         FimDoJogo;
    cycle        *Circular;
    stack<Carta> *monte;
    stack<Carta> *lixo;

    void RetiraJogadorDaRodada(); /// RETIRA JOGADOR COM MAIOR QUANTIDADE DE PONTOS

    Carta CompraCarta(); /// COMPRA UMA CARTA DO MONTE...

    void NovoMonte(); /// REFAZ O MONTE APARTIR DA PILHA LIXO..

    void CartaCastigo(bool &CartaAtivada,bool &SentidoHorario,Iter<list> &Jogador);

public:
    Jogo(int _Numeros_de_Jogadores__);

    ~Jogo();

    void JogaRodada(); /// ATE QUE ALGUM JOGADOR ACABE COM SUAS CARTAS...

    void Leitura_Distribuicao_Cartas();

    bool FimDoJogo__();

    int Ganhador();

};



#endif // JOGO_H
