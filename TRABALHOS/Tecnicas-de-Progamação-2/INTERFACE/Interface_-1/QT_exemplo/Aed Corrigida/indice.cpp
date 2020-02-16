#include "indice.h"
#include "games.h"
#include <fstream>
using namespace std;
#include <iostream>
#include "lig.h"
#include "arquivo.h"
#include <cstring>



indice::indice()
{
    ifstream arq("indice.dat",ios::binary|ios::app);//tenta abrir o arquivo, se nao existir cria

    if(!arq.is_open())///se mesmo assim nao abrir manda uma exceçao , memoria por exemplo
           throw 'a';

    qtd = getqtda();

    if(getqtda()>0)///se for maior que zero significa que existe algo para traser a memoria ram
    {
        this->idgames= new lig[qtd+1];
        arq.seekg(0);
        arq.read((char*)idgames,sizeof(lig)*qtd);
    }
    else///se for igual a zero , nao precisa copiar, porque nao tem nada no arquivo
        this->idgames= new lig[qtd+1];
    arq.close();
}

indice::~indice()
{
    ofstream arq("indice.dat");
    for(int i = 0;i< qtd ;i++)
        arq.write((char*)&idgames[i],sizeof(lig));
    arq.close();
    delete [] idgames;
}

void indice::getnome(char *n, int p)//retorna o nome de acordo com a posicao do vetor
{
    strcpy(n,this->idgames[p].nome);///nunca vai ser maior que qtd
}

int indice::buscab(int pi,int pf,char * nome)
{
        int meio;
        if(pi==pf)
            return pi;
        meio = (pi+pf)/2;
        if(strcmp(nome,this->idgames[meio].nome)>0)
            return buscab(meio+1,pf,nome);
        return buscab(pi,meio,nome);
}

int indice::buscabinaria(char *nome)
{
    int c = buscab(0,qtd-1,nome);
    if(strcmp(this->idgames[c].nome, nome) == 0)
        return c;//caso encontres
    return -1;//caso nao encontre
}

int indice::gravarid(games *p,int posic)//passar como parametro a posicao
{
    char n[30];
    int c;

    p->getnome(n);
    c=buscabinaria(n);

    if(c>=0) //se retornar maior que zero significa que ja existe e retorna a posicao no arquivo grande
        return this->idgames[c].posicao;

    lig aux;

    p->getnome(aux.nome);
    aux.posicao=posic;
    ordenar(&aux);
    qtd++;
    return -2; //significa que gravou ok
}

int indice::getposic(char *nome)
{
    int c=buscabinaria(nome);
     if(strcmp(idgames[c].nome,nome) == 0)
         return idgames[c].posicao;
     return -1;
}

void indice::ordenar(lig *obj)//coloca um lig de modo ordenado
{
    int i=this->qtd-1;

    while( strcmp(obj->nome,idgames[i].nome) < 0 && i >= 0)
    {
            idgames[i+1]=idgames[i];
            i--;
    }
    idgames[i+1] = *obj; //copia o i para i+1
}



int indice::getqtda()
{
    fstream arq("indice.dat",ios::in|ios::binary);
    arq.seekg(0,ios_base::end);
    return arq.tellg()/sizeof(lig);

}
