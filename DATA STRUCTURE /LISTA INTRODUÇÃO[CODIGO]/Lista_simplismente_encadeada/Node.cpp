#include "Node.h"

Node *Node::MontaNode(int C_)
{
    try{
        Node * aux = new Node;
        aux->conteudo = C_;
        aux->next = 0;
        return aux;
    }
    catch(...){
        throw "Não houve como alocar memoria!";
    }
}

void Node::DesmontaNode(Node *No_)
{
    delete No_;
}
