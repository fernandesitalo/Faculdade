#include "games.h"
#ifndef LIG_H
#define LIG_H



class lig
{
public:

    int posicao;
    char nome[30];

public:

    //lig(games *p,int posic);
      lig();
      void setlig(games *p,int posic);
};
#endif // LIG_H
