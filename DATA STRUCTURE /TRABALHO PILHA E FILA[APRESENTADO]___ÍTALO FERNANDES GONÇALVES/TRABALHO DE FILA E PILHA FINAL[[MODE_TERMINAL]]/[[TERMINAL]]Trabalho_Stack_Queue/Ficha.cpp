#include "Ficha.h"

void Ficha::set(int Num_jogador, char Cor_da_ficha, int Torre_da_ficha)
{
    Jogador = Num_jogador;
    Cor = Cor_da_ficha;
    Torre = Torre_da_ficha;
}

int Ficha::getJogador()
{
    return Jogador;
}

char Ficha::getcor()
{
    return Cor;
}

void Ficha::setcor(char Cor_da_ficha)
{
    Cor = Cor_da_ficha;
}

int Ficha::getTorre()
{
    return Torre;
}

void Ficha::setTorre(int Torre_da_ficha)
{
    Torre = Torre_da_ficha;
}

void Ficha::setJogador(int Num_jogador)
{
    Jogador = Num_jogador;
}

Ficha::Ficha(int Jogador_ficha, char Cor_da_ficha, int Torre_de_insercao)
{
    Jogador = Jogador_ficha;
    Cor = Cor_da_ficha;
    Torre = Torre_de_insercao;
}

Ficha::Ficha()
{

}
