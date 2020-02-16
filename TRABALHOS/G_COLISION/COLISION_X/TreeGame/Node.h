#ifndef NODE_H
#define NODE_H

template<class pos,class type>
class Node
{
public:
    Node<pos,type>      *Right;   // FILHO DA DIRETITA
    Node<pos,type>      *Left;    // FILHO DA ESQUERDA
    pos                 Position; // CHAVE DE BUSCA
    type                Conteudo; /// PODERÁ SER UMA PEDRA, UM JOGADOR
    int                 Fb;       // FATOR DE BALANCEAMENTO DA ARVORE AVL

public:

    static Node<pos,type>* MontaNode(pos * pos_ ,type* dado){
        try{
            Node<pos,type> * Novo = new Node<pos,type>();
            Novo->Left     =    0;
            Novo->Right    =    0;
            Novo->Fb       =    0;
            Novo->Position =    *pos_;
            Novo->Conteudo =    *dado;
            return Novo;
        }
        catch(...){
            throw "Erro ao Criar Node";
        }
    }
    static void DesmontaNode(Node<pos,type>* No)
    { delete No;}

    Node();
};

template<class pos,class type>
Node<pos,type>::Node(){ }
#endif // NODE_H
