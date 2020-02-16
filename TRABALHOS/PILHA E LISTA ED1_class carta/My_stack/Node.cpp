#include "Node.h"

Node *Node::MontaNode(Carta *_C_)
{
    Node* p_node = new Node;
    if(!p_node){
        throw "Falha ao Alocar Memoria!";
    }

    p_node->_carta = *_C_;
    p_node->_next = 0;

    return p_node;
}

void Node::DesmontaNode(Node *no) // DELETA DIRETO; SE O PROGAMADOR QUISER, QUE ACESSE O TOPO PRIMEIRO
{
    delete no;
}
Node::Node() {}
