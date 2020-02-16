#include "noded.h"
#include "Aluno.h"

NodeD *NodeD::MontanodeD(Aluno *Conteudo)
{
    NodeD * Novo_Node = new NodeD;


    if(!Novo_Node) throw "Sem espaço para alocar memoria";  /// Lancar execessao

    Novo_Node->next = 0;
    Novo_Node->prev = 0;
    Novo_Node->Conteudo = *Conteudo;

    return Novo_Node;
}

void NodeD::DesmontaNodeD(NodeD *No)
{
    delete No;
}

NodeD::NodeD()
{

}
