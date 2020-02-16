#ifndef DOUBLENODE_H
#define DOUBLENODE_H


template<class type>
class DoubleNode
{
public:
    DoubleNode<type>*   next;
    DoubleNode<type>*   prev;
    type                Conteudo;
    int                 NUM; /// numero do conteiner ou do JOGADOR no MauMau

public:

    static DoubleNode<type> *MontaDoubleNode(type * Conteudo)
    {
        try{
            DoubleNode<type> * Novo_Node = new DoubleNode<type>;
            Novo_Node->next = 0;
            Novo_Node->prev = 0;
            Novo_Node->NUM = 0;
            Novo_Node->Conteudo = *Conteudo;
            return Novo_Node;
        }
        catch(...){
            throw "Ocorreu um erro Inesperado!";
        }
    }
    static void DesmontaDoubleNode(DoubleNode<type> * No)
    {delete No;}

    DoubleNode(){}
};


#endif // DOUBLENODE_H
