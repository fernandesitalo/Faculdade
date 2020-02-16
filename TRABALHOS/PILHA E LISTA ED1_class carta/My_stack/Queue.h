#ifndef QUEUE_H
#define QUEUE_H
#include "Node.h"


class Queue
{
private:
    Node* Head;
    Node* Tail;
    int Qtd_;
public:
    Queue(){Head = Tail = 0;Qtd_ = 0;} // CONSTRUTOR EMBUTIDO NA .H
    ~Queue();
    bool push(Carta *conteudo);
    bool pop();
    Carta* front() const;
    int size() const;
    bool empty() const;

    /*
    METODO 'back' da STL, segundo CPLUSPLUS:
    Retorna uma referência ao último elemento no fila. Este é o elemento "mais novo" na fila (ou seja, o último elemento da fila).
    */
    Carta* back() const;
};

#endif // QUEUE_H
