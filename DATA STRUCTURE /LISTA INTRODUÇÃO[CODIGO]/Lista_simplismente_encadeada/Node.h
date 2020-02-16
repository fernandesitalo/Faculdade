#ifndef NODE_H
#define NODE_H


class Node
{
public:

    int conteudo;
    Node* next;

    static Node* MontaNode(int C_);
    static void DesmontaNode(Node* No_);
};

#endif // NODE_H
