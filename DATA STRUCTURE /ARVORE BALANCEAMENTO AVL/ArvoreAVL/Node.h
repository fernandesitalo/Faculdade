#ifndef NODE_H
#define NODE_H

template<class type>
class Node
{
public:
    Node<type> * Right;
    Node<type> * Left;
    type Conteudo;
    int Fb; // FATOR DE BALANCEAMENTO DA ARVORE AVL

public:

    static Node<type>* MontaNode(type* dado){
        try{
            Node<type> * Novo = new Node<type>();
            Novo->Left = Novo->Right = 0;
            Novo->Fb = 0;
            Novo->Conteudo = *dado;

            return Novo;
        }
        catch(...){
            throw "Erro ao Criar Node";
        }
    }
    static void DesmontaNode(Node<type>* No)
    { delete No;}

    Node();
};

template<class type>
Node<type>::Node()
{ }
#endif // NODE_H
