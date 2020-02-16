#ifndef QUEUE_H
#define QUEUE_H
#include "Node.h"

template<class New_Type>
class queue
{
private:
    Node<New_Type>* Head_;
    Node<New_Type>* Tail_;
    int Quantity_;
public:


    void push(New_Type Conteudo_X);
    void pop();
    New_Type front();
    bool empty();


    queue();
    ~queue();
};

template<class New_Type>
void queue<New_Type>::push(New_Type Conteudo_X)
{
    try{
        Node<New_Type>* Novo_Node = Node<New_Type>::MontaNode(&Conteudo_X);
        Novo_Node->next = 0;// Garantir o que Foi feito na MontaNode

        if(!Head_){ // Se for o primeiro, então o Head_ aponta para ele
            Head_ = Novo_Node;
        }
        else{ // Se ele nao for o primeiro,Quem estiver em Tail_ aponta para o novo NodeCriado;
            Tail_->next = Novo_Node;
        }
        Tail_ = Novo_Node;
        Quantity_++;
    }
    catch(const char *erro){
        throw erro;
    }
}

template<class New_Type>
void queue<New_Type>::pop()
{
    if(!Head_) return;

    Node<New_Type>* aux = Head_;
    Head_ = Head_->next;// aponta para o proximo da fila(Qm estiver atrás de Head_ foda_se qm é)

    if(!Head_)    // Se após a remoção, não existir mais elementos, o Tail_ aponta para o endereco de memoria deletado
        Tail_ = 0;// Por isso vamos apontalo pra null... pra evitar merdas

    Node<New_Type>::DesmontaNode(aux);
    Quantity_--;
}

template<class New_Type>
New_Type queue<New_Type>::front()
{
    New_Type aux = Head_->conteudo;
    return aux;
}

template<class New_Type>
bool queue<New_Type>::empty(){return(!Head_);}

template<class New_Type>
queue<New_Type>::queue()
{
    Head_ = Tail_ = 0;
    Quantity_ = 0;
}

template<class New_Type>
queue<New_Type>::~queue()
{
    while(Head_){
        Node<New_Type> *aux = Head_;
        Head_ = Head_->next;
        Node<New_Type>::DesmontaNode(aux);
    }
    Quantity_ = 0;
}

#endif // QUEUE_H
