#ifndef NODE_H
#define NODE_H
#include "Carta.h"

class Node
{
public:
    Carta _carta;
    Node* _next;

    static Node* MontaNode(Carta * _C_);
    static void DesmontaNode(Node *no);
    Node();
};

#endif // NODE_H
