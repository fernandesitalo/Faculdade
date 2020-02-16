#ifndef NODE_H
#define NODE_H




template<class _tp>
class Node
{
public:
    int conteudo;
    Node<_tp>* next;

public:
    Node(){}
    static Node<_tp>* MontaNode(_tp * c);
    static void DesmontaNode(Node<_tp>* No);
};

template<class _tp>
Node<_tp> *Node<_tp>::MontaNode(_tp *c)
{
    Node<_tp>* aux = new Node<_tp>;
    aux->conteudo = *c;
    aux->next = 0;
    return aux;
}


template<class _tp>
void Node<_tp>::DesmontaNode(Node<_tp> *No)
{
    delete No;
}

#endif // NODE_H
