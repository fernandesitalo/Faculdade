#ifndef LISTA_SO_H
#define LISTA_SO_H
#include "Node.h"

class Lista_SO
{
private:
    Node* Head;
    int qtd;
public:
    Lista_SO();
    ~Lista_SO();
    bool push(int* c);
    bool pop(int c, int*conteudo_aux);
                /// c é a carta!
    int size();
};

Lista_SO::Lista_SO()
{
    Head = 0; // NULL
    qtd = 0;
}

Lista_SO::~Lista_SO()
{
    Node* P = Head;

    while(P){
       Node* aux = P;
       P = P->next;
       delete aux;
    }
    Head = 0;
    qtd = 0;
}

bool Lista_SO::push(int *c)
{
    Node** P = &Head;
    Node* No_Inserir = Node::MontaNode(c);

    ///ENQUANTO A CHAVE A SER INSERIDA FOR MENOR.

    while((*P) && ( (*P)->key ) < (No_Inserir->key) ){
        P = &(*P)->next; // P recere o endereço de memoria do proximo Node
    }

    /// SAI DO WHILE COM O LOCAL DE INSERCAO;

    No_Inserir->next = (*P);
    (*P) = No_Inserir;
    return true;
}

bool Lista_SO::pop(int c, int *conteudo_aux)
{
    int K = c; // K recebe a chave do objeto 'carta'

    Node** P = &Head;

    ///ENQUANTO A CHAVE A SER INSERIDA FOR MENOR.

    while((*P) && ( (*P)->key ) < K){
        P = &(*P)->next; // P recere o endereço de memoria do proximo Node
    }

    if(!(*P)) return false;

    Node* PN = *P;
    *P = PN->next;

    *conteudo_aux = PN->conteudo;
    Node::DesmontaNode(PN);

    return true;
}

int Lista_SO::size()
{
    return qtd;
}

#endif // LISTA_SO_H
