#include "List.h"
#include <stdio.h>

void List::push(int conteudo)
{
    try{
        Node* aux =  Node::MontaNode(conteudo);
        aux->next = 0;

        if(!Head_) {
            Head_ = aux;
            return;
        }

        Node *P = Head_;
        while(P->next){
            P = P->next;
        }
        P->next = aux;
        qtd_++;
    }
    catch(const char *erro){
        throw erro;
    }
}


void List::push_2(int conteudo)
{
    try{
        Node* aux =  Node::MontaNode(conteudo);// é lançado um throw se der alguma coisa errada
        aux->next = 0;


        if(Head_){
            aux->next = Head_;
        }

        Head_ = aux;

        qtd_++;
    }
    catch(const char *erro){
        throw erro;
    }
}

bool List::pop(int k)
{
    Node** P = &Head_;


    for( ;(*P)->conteudo != k; P = &(*P)->next);

    if(!(*P)) return false;

    /// Achamos

    Node*PN = *P;
    *P = PN->next;
    Node::DesmontaNode(PN);
    qtd_--;
    return true;
}

int List::size(){return qtd_;}



bool List::search(int k)
{
    Node* P = Head_;

    for(;P && P->conteudo != k ; P = P->next);

    if(!P) return false;

    return true;
}

void List::teste()
{
    Node* aux = Head_;
    while(aux){
     printf("%d\n",aux->conteudo);
     aux = aux->next;
    }
}

List::~List()
{
    while(Head_){
        Node* aux = Head_;
        Head_ = Head_->next;
        Node::DesmontaNode(aux);
    }
    qtd_ = 0;
}

List::List(){Head_ = 0;qtd_ = 0;}
