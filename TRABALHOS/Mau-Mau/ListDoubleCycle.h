#ifndef LISTDOUBLECYCLE_H
#define LISTDOUBLECYCLE_H
#include "DoubleNode.h"
#include <stdio.h>

namespace my{
template<class type>
class ListDoubleCycle;

template<class type>
class Iter
{
private:
    friend class ListDoubleCycle<type>; /// friend
    DoubleNode<type> *current;

public:
    Iter(DoubleNode<type> * at){current = at;}
    Iter(){current = 0;}

    type operator*()
    {return current->Conteudo;}

    void operator++()
    {current = current->next;}

    void operator--()
    {current = current->prev;}

    type* operator->()
    { return &current->Conteudo;}

    int NumConteiners(){return current->NUM;}
};


/// LISTA DUPLAMENTE ENCADEADA CIRCULAR
template<class type>
class ListDoubleCycle
{
private:
   DoubleNode<type>*    Head;
   int                  qtd;

public:
    typedef Iter<type> iterator;

    ListDoubleCycle();

    ListDoubleCycle(int Num, type __aux);

    void EnumeraConteiners();

    int GetNumeroDoConteiner();

    ~ListDoubleCycle();

    void push(type *Dado);

    void push(type Dado);

    bool pop(Iter<type> &it);

    int size(){return qtd;}

    void ClearList();

    void Clear();

    Iter<type> begin(){return Iter<type>(this->Head);}
};



template<class type>
void ListDoubleCycle<type>::push(type *Dado)
{
    /// 1 - criar o no a ser inserido na lista
    DoubleNode<type>* No_a_ser_inserido = DoubleNode<type>::MontaDoubleNode(Dado); // se der merda ja lança excessao

    if(!Head){ // caso for o primeiro node a ser inserido
        Head = No_a_ser_inserido->next = No_a_ser_inserido->prev = No_a_ser_inserido;
        qtd++;
        return;
    }
    No_a_ser_inserido->next = Head;
    No_a_ser_inserido->prev = Head->prev;
    Head->prev = No_a_ser_inserido;
    No_a_ser_inserido->prev->next = No_a_ser_inserido;
    Head = No_a_ser_inserido;
    qtd++;
}



template<class type>
void ListDoubleCycle<type>::push(type Dado)
{
    /// 1 - criar o no a ser inserido na lista
    DoubleNode<type>* No_a_ser_inserido = DoubleNode<type>::MontaDoubleNode(&Dado); // se der merda ja lança excessao

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
bool ListDoubleCycle<type>::pop(Iter<type> &it){
    DoubleNode<type> *P = Head;

    if(P == it.current){} // e o primeiro elemento
    else
    {
        P = P->next;
        while(P != Head && P != it.current){ P = P->next;}
    }

    if(P != it.current) return false; // não achou

    if(P == P->next)
    {/// 1º - Pode ser que seja o unico elemento da lista
        Head = 0;
        it.current = 0;
    }
    else
    {/// 2º - primeiro elemento mas nao unico
        if(Head == P)
            Head = Head->next;

        /// 3º - interseção dos casos... o que deve ser feito sempre que e o 2ºcaso e o que nao e o 1º caso
        P->next->prev = P->prev; // o proximo elemento a 'P' apontara para o anterior a 'P'
        P->prev->next = P->next; // o elemento anterior a 'P' aponta para o proximo de 'P'
        ++it; //aponta para o proximo elemento
    }
    DoubleNode<type>::DesmontaDoubleNode(P);
    qtd--;
    return true;
}

template<class type>
void ListDoubleCycle<type>::ClearList(){
    iterator it = begin();
    for(int i = 0 ; i < qtd ; ++i,++it){
        it->clear();
    }
}

template<class type>
void ListDoubleCycle<type>::Clear()
{
    if(Head){
        DoubleNode<type>*P = Head;
        DoubleNode<type>*aux = 0;

        while(P->next != Head){
            aux = P;
            P = P->next;
            delete aux;
        }
        delete P;
        Head = 0;
        qtd = 0;
    }
}

template<class type>
ListDoubleCycle<type>::ListDoubleCycle(){Head = 0;qtd = 0;}


template<class type>
ListDoubleCycle<type>::ListDoubleCycle(int Num,type __aux){
    Head = 0; qtd = 0;
    while(Num--) this->push(__aux);
}

template<class type>
void ListDoubleCycle<type>::EnumeraConteiners(){
    DoubleNode<type> *P = Head;
    int cont = 1;
    if(P){
        P->NUM = cont++;
        P = P->next;
    }
    while(P != Head){
        P->NUM = cont++;
        P = P->next;
    }
}

template<class type>
ListDoubleCycle<type>::~ListDoubleCycle(){Clear();}
}

#endif // LISTDOUBLECYCLE_H
