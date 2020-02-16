#include "Carta.h"
#include <iostream>
#include <stdio.h>
using namespace std;
using namespace my;

void Carta::setCarta(char _valor__, char _naipe__)
{
    naipe = _naipe__;
    valor = _valor__;
}

void Carta::printCarta()
{
    printf("%c %c \n",valor,naipe);
    //cout<< valor << "   " << naipe << endl;
}

char Carta::getNaipe(){
    return naipe;
}

char Carta::getValor()
{
    return valor;
}

bool Carta::operator < (Carta  C) const // SOBRECARREGADO DE ACORDO COM O JOGO MAUMAU
{
    // SEMPRE O MAIOR VALOR
    // SE FOR O MESMO VALOR, VEM A SEQUENCIA PAUS(0),COPAS(1),ESPADA(2),OURO(3)
    if(this->valor > C.valor || (this->valor >= C.valor && this->naipe < C.naipe)) return true;/// VALOR IGUAL, DECIDIR PELO NAIPE
    return false;                                                    /// ORDEM DE DESCARTE : 0,1,2,3
}

bool Carta::operator!=(Carta C) const
{
    return (this->valor != C.valor && this->naipe != C.naipe);
}

bool Carta::operator==(Carta C) const
{
    return (this->valor == C.valor || this->naipe == C.naipe);
}

Carta::Carta(char valor__,char naipe__)
{
    valor = valor__;
    naipe = naipe__;
}

Carta::Carta(){}

Carta my::make_carta(char valor__, char naipe__)
{
    return Carta(valor__,naipe__);
}
