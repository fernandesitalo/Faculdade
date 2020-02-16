#include <math.h>
#include "equipe.h"

int equipe::getINSCR()
{
    return INSCR;
}

void equipe::setINSCR(int INSCR)
{
    this->INSCR = INSCR;
}

/* pontos da etapa 1*/
int equipe::getT2()
{
    return tempo[0];
}

void equipe::setT1(int t)
{
    tempo[0] = t;
}

/* pontos da etapa 2*/
int equipe::getT1()
{
    return tempo[1];
}

void equipe::setT2(int t)
{
    tempo[1] = t;
}

/* pontos da etapa 3*/
int equipe::getT3()
{
    return tempo[2];
}

void equipe::setT3(int t)
{
    tempo[2] = t;
}



/*CALCULO DOS PONTOS DA ETAPA*/
float equipe::getPET(int tempoPadrao, int etapa)
{
    int delta = fabs(tempoPadrao - tempo[etapa - 1]);

    if(delta < 3)
    {
        return 100;
    }

    if(delta <= 5)
    {
        return 80;
    }

    return 80 - (80 - delta)/5.0;
}



