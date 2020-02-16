#ifndef NODE_H
#define NODE_H


template<class type>
class Node
{
public:
    Node<type>* Right;
    Node<type>* Left;
    type Conteudo;
    ///atributo fator de balanceamento

public:
    static Node<type> *MontaNode(type *conteudo);
    static void DesmontaNode(Node<type> *No);
    Node();
};

template<class type>
Node<type> *Node<type>::MontaNode(type *conteudo)
{
    try{
        Node<type> * Novo = new Node<type>;
        Novo->Left = Novo->Right = NULL;
        Novo->Conteudo = *conteudo;
        return Novo;
    }catch(...){
        throw "Algo deu errado ao alocar um novo Conteiner!";
    }
}

template<class type>
void Node<type>::DesmontaNode(Node<type> *No)
{
    delete No;
}

template<class type>
Node<type>::Node(){}

#endif // NODE_H
