#ifndef LISTADE_H
#define LISTADE_H
#include "noded.h"


template<class _tp>
class Iter
{
public:
    NodeD<_tp> *current;

public:
    Iter(NodeD<_tp> * at){current = at;}
    Iter(){current = 0;}

    _tp operator*()
    {return current->Conteudo;}

    void operator++()
    {current = current->next;}

    void operator--()
    {current = current->prev;}
};




/// LISTA DUPLAMENTE ENCADEADA CIRCULAR
template<class type>
class ListaDE
{
private:
   NodeD<type>* Head;
   int qtd;
public:        
    typedef Iter<type> iterator;
    ListaDE(){Head = 0;qtd = 0;}
    ~ListaDE();
    void push(type *Dado);
    bool pop(Iter<type> it);
    int size(){return qtd;}
    Iter<type> begin(){return Iter<type>(this->Head);}
};



template<class type>
void ListaDE<type>::push(type *Dado)
{
    /// 1 - criar o no a ser inserido na lista
    NodeD<type>* No_a_ser_inserido = NodeD<type>::MontanodeD(Dado); // se der merda ja lança excessao

    if(!Head){ // caso for o primeiro node a ser inserido
        Head = No_a_ser_inserido->next = No_a_ser_inserido->prev = No_a_ser_inserido;
        qtd++;
        return;
    }
    No_a_ser_inserido->next = Head;
    No_a_ser_inserido->prev = Head->prev;

    No_a_ser_inserido->prev->next = No_a_ser_inserido;
    Head->prev = No_a_ser_inserido;

    Head = No_a_ser_inserido;
    qtd++;
}

template<class type>
bool ListaDE<type>::pop(Iter<type> it){

    NodeD<type> *P = Head;

    if(P == it.current){} // e o primeiro elemento
    else{
        P = P->next;
        while(P != Head && P != it.current){ P = P->next;}
    }

    if(P != it.current) return false; // não achou

    /// 1º - Pode ser que seja o unico elemento da lista
    if(P == P->next){
        Head = 0;
    }
    else{
        /// 2º - primeiro elemento mas nao unico
        if(Head == P)
            Head = Head->next;

        P->next->prev = P->prev; // o proximo elemento a 'P' apontara para o anterior a 'P'
        P->prev->next = P->next; // o elemento anterior a 'P' aponta para o proximo de 'P'
    }

    NodeD<type>::DesmontaNodeD(P);
    qtd--;
    return true;
}

template<class type>
ListaDE<type>::~ListaDE()
{
    if(Head){
        NodeD<type>*P = Head;
        NodeD<type>*aux = 0;

        while(P->next != Head){
            aux = P;
            P = P->next;
            delete aux;
        }
        delete P;
        Head = 0;
    }
}

#endif // LISTADE_H
