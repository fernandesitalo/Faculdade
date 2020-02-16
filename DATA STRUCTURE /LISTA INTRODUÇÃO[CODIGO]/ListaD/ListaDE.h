#ifndef LISTADE_H
#define LISTADE_H
#include "noded.h"
#include "Aluno.h"

class ListaDE // circular
{
private:
   NodeD* Head;

public:
    ListaDE();
    ~ListaDE();
    bool push(Aluno *Dado);
    bool pop(int K,Aluno * obj);




    void printLista();

};

#endif // LISTADE_H
