#ifndef STACK_H
#define STACK_H
#include "Node.h"
#include "Carta.h"
class Stack
{
private:
    Node* _top;
    int _qtd;

public:
    bool push(Carta *carta);
    bool pop();
    Carta* top();
    int size();
    bool emtpy();


    Stack();
    ~Stack();
};

#endif // STACK_H
