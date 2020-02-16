#ifndef LISTSIMPLE_H
#define LISTSIMPLE_H

#include "Node.h"

template<class New_Type>
class ListSimple
{
private:
    Node<New_Type>* Head;

public:

    void clear();

    void push(New_Type * C_); // só insere ordenadamente.

    void push(New_Type C_);

    bool pop(New_Type * Chave , New_Type * C_);

    ~ListSimple();

    ListSimple();
};


/*
template<class New_Type>
void ListSimple<New_Type>::push(New_Type *C_)
{
/// INSERIR ORDENADAMENTE
    try{
        Node<New_Type>* No_Inserir = Node::MontaNode(C_);

        Node<New_Type>**P = &Head;

        while((*P) && (*P)->Conteudo < *No_Inserir){

        }





    }
}

*/

template<class New_Type>
ListSimple<New_Type>::ListSimple()
{
    Head = 0;
}




#endif // LISTSIMPLE_H
