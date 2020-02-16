#ifndef LISTSORTEDSIMPLE_H
#define LISTSORTEDSIMPLE_H

#include "SimpleNode.h"

namespace my{
template<class type>
class ListSortedSimple
{
private:
    SimpleNode<type>*   Head;
    int                 qtd;

public:
    ListSortedSimple();

    ListSortedSimple(int Num,type __aux);

    ~ListSortedSimple();

    void push(type * c);

    void push(type c);

    bool pop(type * TopoDoLixo, type *CartaAux = 0);

    bool pop_front(type * CartaAux = 0);

    bool pop(type TopoDoLixo, type *CartaAux);

    int size(){ return qtd;}

    bool Empty(){return !(Head);}

    void clear();

    int Pontos();
};


template<class type>
ListSortedSimple<type>::ListSortedSimple(){Head = 0;qtd = 0;}


template<class type>
ListSortedSimple<type>::ListSortedSimple(int Num,type __aux){
    Head = 0; qtd = 0;
    while(Num--){push(&__aux);}
}


template<class type>
ListSortedSimple<type>::~ListSortedSimple()
{
    SimpleNode<type>* P = Head;
    while(P){
        SimpleNode<type>* aux = P;
        P = P->next;
       delete aux;
    }
    Head = 0;
    qtd = 0;
}



template<class type>
void ListSortedSimple<type>::push(type *c)
{
    SimpleNode<type>* No_Inserir = SimpleNode<type>::MontaSimpleNode(c);

    if(!Head){
        Head = No_Inserir;
        qtd++;
        return;
    }
    SimpleNode<type>** P = &Head;
    ///ENQUANTO A CHAVE A SER INSERIDA FOR MENOR
    while((*P) && (*P)->conteudo < *c){ //c == No_Inserir->conteudo
        P = &(*P)->next; // P recere o endereço de memoria do proximo Node
    }
    /// SAI DO WHILE COM O LOCAL DE INSERCAO;
    No_Inserir->next = (*P);
    (*P) = No_Inserir;
    qtd++;
}



template<class type>
void ListSortedSimple<type>::push(type c)
{
    SimpleNode<type>* No_Inserir = SimpleNode<type>::MontaSimpleNode(&c);
    if(!Head){
        Head = No_Inserir;
        qtd++;
        return;
    }
    SimpleNode<type>** P = &Head;
    ///ENQUANTO A CHAVE A SER INSERIDA FOR MENOR.
    while((*P) && (*P)->conteudo < c){ //c == No_Inserir->conteudo
        P = &(*P)->next; // P recere o endereço de memoria do proximo Node
    }
    /// SAI DO WHILE COM O LOCAL DE INSERCAO;

    No_Inserir->next = (*P);
    (*P) = No_Inserir;
    qtd++;
}




template<class type>
bool ListSortedSimple<type>::pop(type * TopoDoLixo, type *CartaAux)
{
    SimpleNode<type>** P = &Head;
    ///ENQUANTO A CHAVE A SER INSERIDA FOR MENOR.
    while((*P) && (*P)->conteudo != *TopoDoLixo){ // A sobrecarga de operador definira esta etapa

        P = &(*P)->next; // P recere o endereço de memoria do proximo SimpleNode
    }
    if(!(*P)) return false;
    SimpleNode<type>* PN = *P;
    *P = PN->next;
    *CartaAux = PN->conteudo;
    SimpleNode<type>::DesMontaSimpleNode(PN);
    qtd--;
    return true;
}

template<class type>
bool ListSortedSimple<type>::pop_front(type *CartaAux)
{
    if(!Head) return false;
    SimpleNode<type>* PN = Head;
    Head = Head->next;
    if(CartaAux) *CartaAux = PN->conteudo;
    SimpleNode<type>::DesmontaSimpleNode(PN);
    qtd--;
    return true;
}


template<class type>
bool ListSortedSimple<type>::pop(type  TopoDoLixo, type *CartaAux)
{
    SimpleNode<type>** P = &Head;
    ///ENQUANTO A CHAVE A SER INSERIDA FOR DIFERENTE
    while((*P) && (*P)->conteudo != TopoDoLixo){ // A sobrecarga de operador definira esta etapa
        P = &(*P)->next; // P recere o endereço de memoria do proximo SimpleNode
    }
    if(!(*P)){ // nao tem carta que possa ser removida
        return false;
    }
    SimpleNode<type>* PN = *P;
    *P = PN->next;
    if(CartaAux) *CartaAux = PN->conteudo;
    SimpleNode<type>::DesmontaSimpleNode(PN);
    qtd--;
    return true;
}

template<class type>
void ListSortedSimple<type>::clear(){
    SimpleNode<type>* P = Head;
    while(P){
        SimpleNode<type>* aux = P;
        P = P->next;
        delete aux;
    }
    Head = 0;
    qtd = 0;
}

template<class type>
int ListSortedSimple<type>::Pontos(){
    SimpleNode<type> * P = Head;
    int _pontos__ = 0;
    while(P){
        _pontos__ += P->conteudo.getValor() - '@';//TABELA ASCII
        P = P->next;
    }
    return _pontos__;
}
}
#endif // LISTSORTEDSIMPLE_H
