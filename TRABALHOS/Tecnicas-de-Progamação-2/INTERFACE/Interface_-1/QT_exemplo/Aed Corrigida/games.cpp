#include "games.h"
#include <cstring>
#include <iostream>
using namespace std;
games::games()
{

}

void games::setnome(const char *n )
{
    if(strlen(n)==0)
        throw 1;
    strcpy(this->nome,n);
}

void games::setconsole(const char *n)
{
    if(strlen(n)==0)
        throw 2;
    strcpy(this->console,n);
}

void games::setcod(long long int n)
{
    this->codigo=n;
}

void games::setetaria(int n)
{
    this->faixa=n;
    if(n>18||n<=0)
        throw 3;
}

void games::setgenero(const char *n)
{
    if(strlen(n)==0)
        throw 4;
    strcpy(this->genero,n);
}

void games::setvalor(float n)
{
    this->valor=n;
    if(n>1000||n<0)
        throw 5;
}

void games::setqtd(int n)
{
    this->qtd=n;
    if(n<0)
        throw 6;
}

int games::getcod()
{
    return codigo;
}

int games::getetaria()
{
    return this->faixa;
}

int games::getqtd()
{
    return qtd;
}

float games::getvalor()
{
    return valor;
}

void games::getnome(char *n)
{

    strcpy(n,this->nome);
}

void games::getconsole(char *n)
{

    strcpy(n,this->console);
}

void games::getgenero(char *n)
{

    strcpy(n,this->genero);
}
