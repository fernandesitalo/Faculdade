#ifndef NODED_H
#define NODED_H
#include "Aluno.h"



template<class type>
class NodeD
{
public:
    NodeD<type>* next;
    NodeD<type>* prev;
    type Conteudo;


public:
    static NodeD<type> *MontanodeD(type * Conteudo)
    {
        NodeD<type> * Novo_Node = new NodeD<type>;


        if(!Novo_Node) throw "Sem espaço para alocar memoria";  /// Lancar execessao

        Novo_Node->next = 0;
        Novo_Node->prev = 0;
        Novo_Node->Conteudo = *Conteudo;

        return Novo_Node;
    }
    static void DesmontaNodeD(NodeD<type> * No)
    {
        delete No;
    }

    NodeD()
    {

    }
};

#endif // NODED_H
