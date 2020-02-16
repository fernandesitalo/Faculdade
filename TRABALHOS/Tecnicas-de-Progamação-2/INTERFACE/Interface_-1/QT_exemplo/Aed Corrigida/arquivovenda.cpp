#include "arquivovenda.h"
#include <fstream>
#include "games.h"
using namespace std;
#include <iostream>
#include "indice.h"
#include "cadastro.h"

arquivovenda::arquivovenda()
{

    fstream arq("venda.dat",ios::out|ios::binary|ios::app);
        if(!arq.is_open())//verifica se o arquivo ja existe
        {
          ofstream arq("venda.dat");
          //throw 1;
          arq.close();
        }
        arq.close();
}


void arquivovenda::gravarF(vendas *p)//grava apenas no final
{
    fstream arq("venda.dat",ios::out|ios::binary|ios::app);
        if(!arq.is_open())//verifica se o arquivo ja existe
        {
          ofstream arq("venda.dat");
          //throw 1;
        }
    arq.write((char*)p,sizeof(vendas));
    arq.close();

}


void arquivovenda::ler(vendas *p,int pos)
{
    fstream arq("venda.dat",ios::in|ios::binary);
    if(!arq.is_open())
    {
        ofstream arq("venda.dat");
     //   throw 'a';// nao existem clientes cadastrados
    }

    //if(pos >= getqtda())///tentar pegar de uma posiçao inexistente
        //throw 1;
    arq.seekg((pos)*sizeof(vendas));
    arq.read((char*)p,sizeof(vendas));
    arq.close();

}

void arquivovenda::sobrescrever(vendas *p, int pos)
{

    fstream arq("venda.dat",ios_base::binary|ios_base::in|ios_base::out);
    if(!arq.is_open())//verifica se o arquivo ja existe
    {
          //ofstream arq("games.dat");
         throw 1;
    }
    //if(pos >= getqtda())///tentar gravar de uma posiçao inexistente
      //  throw 1;
    arq.seekp((pos)*sizeof(vendas),ios_base::beg);
    arq.write((char*)p,sizeof(vendas));
    arq.close();
}

int arquivovenda::getqtda()
{
    fstream arq("venda.dat",ios::in|ios::binary);
    if(!arq.is_open())
    {
        ofstream arq("venda.dat");
     //   throw 'a';// nao existem clientes cadastrados
    }
    arq.seekg(0,ios_base::end);
    return arq.tellg()/sizeof(vendas);
}

