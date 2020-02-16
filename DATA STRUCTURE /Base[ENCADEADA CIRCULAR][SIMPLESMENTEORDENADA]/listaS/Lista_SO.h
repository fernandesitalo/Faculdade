#ifndef LISTA_SO_H
#define LISTA_SO_H
#include "Node.h"



template<class type>
class Lista_SO
{
private:
    Node<type>* Head;
    int qtd;

public:
    Lista_SO(){Head = 0;qtd = 0;}
    ~Lista_SO();
    void push(type * c);
    bool pop(type * TopoDoLixo, type *CartaAux);
    int size(){ return qtd;}
    bool Empty(){return !(Head);}
};





template<class type>
Lista_SO<type>::~Lista_SO()
{
    Node<type>* P = Head;
    while(P){
       Node<type>* aux = P;
       P = P->next;
       delete aux;
    }
    Head = 0;
    qtd = 0;
}



template<class type>
void Lista_SO<type>::push(type *c)
{
    Node<type>** P = &Head;
    Node<type>* No_Inserir = Node<type>::MontaNode(c);

    ///ENQUANTO A CHAVE A SER INSERIDA FOR MENOR.
    ///
    while((*P) && (*P)->conteudo < *c){ //c == No_Inserir->conteudo
        P = &(*P)->next; // P recere o endereço de memoria do proximo Node
    }
    /// SAI DO WHILE COM O LOCAL DE INSERCAO;

    No_Inserir->next = (*P);
    (*P) = No_Inserir;
    qtd++;
}





template<class type>
bool Lista_SO<type>::pop(type * TopoDoLixo, type *CartaAux)
{

    Node<type>** P = &Head;

    ///ENQUANTO A CHAVE A SER INSERIDA FOR MENOR.

    while((*P) && (*P)->conteudo != *TopoDoLixo){ // A sobrecarga de operador definira esta etapa
        P = &(*P)->next; // P recere o endereço de memoria do proximo Node
    }

    if(!(*P)) return false;

    Node<type>* PN = *P;
    *P = PN->next;

    *CartaAux = PN->conteudo;
    Node<type>::DesmontaNode(PN);
    qtd--;
    return true;
}




#endif // LISTA_SO_H
